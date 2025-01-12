// �����, �������� ������� ���������� � ������������ + �����������
#include "UsersData.h"


UsersData::UsersData()
{
}

void UsersData::setName(string name)
{
	this->name = name;
}

string UsersData::getName()
{
	return this->name;
}

void UsersData::setLastName(string lastName)
{
	this->lastName = lastName;
}

string UsersData::getLastName()
{
	return this->lastName;
}

void UsersData::setPatronymic(string patronymic)
{
	this->patronymic = patronymic;
}

string UsersData::getPatronymic()
{
	return this->patronymic;
}

void UsersData::setAdress(string adrees)
{
	this->adress = adress;
}

string UsersData::getAdress()
{
	return this->adress;
}

void UsersData::setPhone(string phone)
{
	this->phone = phone;
}

string UsersData::getPhone()
{
	return this->phone;
}

void UsersData::setLogin(string login)
{
	this->login = login;
}

string UsersData::getLogin()
{
	return this->login;
}

void UsersData::setPassword(string password)
{
	this->password = password;
}

string UsersData::getPassword()
{
	return this->password;
}

void UsersData::setPathToUsersData(string pathToUsersData)
{
	this->pathToUsersData = pathToUsersData;
}

string UsersData::getPathToUsersData()
{
	return this->pathToUsersData;
}

string UsersData::normalizePhoneNumber(const string& phone) // ������� ����������� ������ ��������
{
	string result;

	// ��������� �� ������� ������� � ������
	for (char ch : phone) {
		if (isdigit(ch)) {
			result += ch;  // ��������� ������ �����
		}
	}

	// ���� ����� ���������� � "+7", �������� ��� �� "8"
	if (result.size() > 0 && result[0] == '7') {
		result[0] = '8';  // �������� ������ ����� �� 8
	}

	return result;
}

bool UsersData::loginCheck(const string& login, string pathToUsersData) // ������� ��� ��������, ����� �� �����
{
    string line = "";
	ifstream in;
	in.open(pathToUsersData);
    while (getline(in, line)) {  // ������ ���� ���������
        stringstream ss(line);  // ����� ��� ���������� ������
        string name, lastName, patronymic, userLogin, password, address, phone;

        // ��������� ������ �� ������� ':'
        if (getline(ss, name, ':') && 
            getline(ss, lastName, ':') &&
            getline(ss, patronymic, ':') &&
            getline(ss, userLogin, ':') &&
            getline(ss, password, ':') &&
            getline(ss, address, ':') &&
            getline(ss, phone)) {
            
            // ���������� ����� � ������� ��������� � ������
            if (userLogin == login) {
				in.close();  // ��������� ����
                return true;   // ����� �����
            }
        }
    }

	in.close();  // ��������� ����
    return false;  // ����� ��������
}



void UsersData::registration()
{
	string name, lastName, patronymic, adress, phone, login, password;
	string pathToUsersData = "Data.txt";
	cout << "\t\t** Registration **" << endl;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << "Enter your patronymic: ";
	cin >> patronymic;
	cout << "Enter your adress: ";
	cin >> adress;
	cout << "Enter your phone: ";
	cin >> phone;
	phone = normalizePhoneNumber(phone); // �������� ������� � ������ ���� ��� "+7", ������� ��� �� "8"
	do {
		cout << "Enter your login: ";
		cin >> login;
		if (login.size() > 8) {
			cout << "Login is too long. Use another one." << endl;
		}
		if (loginCheck(login, pathToUsersData) == true || login == "admin" || login == "Admin") {
			cout << "Login is already used. Use another one." << endl;
		}
	} while (loginCheck(login, pathToUsersData) == true || login.size() > 8 || login == "admin" || login == "Admin");
	do {
		cout << "Enter your password: ";
		cin >> password;
		if (password.size() > 8) {
			cout << "The password is too long. Use another one." << endl;
		}
	} while (password.size() > 8);

	// ����� ����� ������������ �������� ������ � ������

	// ��������� ���� ��� ������
	ofstream file(pathToUsersData, ios::app);
	if (!file.is_open()) {
		cout << "Unable to open file for writing.\n";
		return;
	}

	// ���������� ������ ������������ � ����
	file << name << ":" << lastName << ":" << patronymic << ":"
		<< login << ":" << password << ":" << adress << ":" << phone << endl;

	file.close();
	cout << "Registration successful!" << endl;
}


// ������� ��� ����������� ������������
bool UsersData::loginUser()
{
	int attemptCount = 0;  // ������� ��������� �������
	string pathToUsersData = "Data.txt";
	string inputLogin, inputPassword;
	cout << "\t\t** Authorization **" << endl;

	// ����������� ����� � ������
	cout << "Enter your login: ";
	cin >> inputLogin;
	// ���������, ���� �� ���� ����� � �����
	if (!loginCheck(inputLogin, pathToUsersData)) {
		cout << "Login not found. Redirecting to registration..." << endl;
		registration();  // ������� � �����������
		return false;  // ����� �� ������
	}
	// ���� ��� ������� ����� ������ (�� 3 �������)
	while (attemptCount < 3) {
		cout << "Enter your password: ";
		cin >> inputPassword;

		// ��������� ���� ��� ������
		ifstream in(pathToUsersData);
		if (!in.is_open()) {
			cout << "Unable to open file.\n";
			return false;
		}

		string line;
		bool loginFound = false;
		while (getline(in, line)) {  // ������ ���� ���������
			stringstream ss(line);  // ����� ��� ���������� ������
			string name, lastName, patronymic, userLogin, userPassword, address, phone;

			// ��������� ������ �� ������� ':'
			if (getline(ss, name, ':') &&
				getline(ss, lastName, ':') &&
				getline(ss, patronymic, ':') &&
				getline(ss, userLogin, ':') &&
				getline(ss, userPassword, ':') &&
				getline(ss, address, ':') &&
				getline(ss, phone)) {

				// ���������� ����� � ������
				if (userLogin == inputLogin && userPassword == inputPassword) {
					in.close();  // ��������� ����
					cout << "Authorization successful!" << endl;
					return true;  // �������� �����������
				}
			}
		}

		in.close();  // ��������� ����
		cout << "Invalid login or password. Try again." << endl;
		attemptCount++;  // ����������� ������� �������

		if (attemptCount == 3) {
			cout << "You have entered wrong password 3 times." << endl;
			cout << "You will now be redirected to the registration page." << endl;
			return false;  // ��������� ������� �����������
			registration();  // ��������� � �����������
		}
	}
}

UsersData::~UsersData()
{
}
