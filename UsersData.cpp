// класс, хранящий основню информацию о пользователе + регистрация
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

string UsersData::normalizePhoneNumber(const string& phone) // функция исправления номера телефона
{
	string result;

	// Пробегаем по каждому символу в строке
	for (char ch : phone) {
		if (isdigit(ch)) {
			result += ch;  // Добавляем только цифры
		}
	}

	// Если номер начинается с "+7", заменяем его на "8"
	if (result.size() > 0 && result[0] == '7') {
		result[0] = '8';  // Заменяем первую цифру на 8
	}

	return result;
}

bool UsersData::loginCheck(const string& login, string pathToUsersData) // Функция для проверки, занят ли логин
{
    string line = "";
	ifstream in;
	in.open(pathToUsersData);
    while (getline(in, line)) {  // Читаем файл построчно
        stringstream ss(line);  // Стрим для разделения строки
        string name, lastName, patronymic, userLogin, password, address, phone;

        // Разделяем строку по символу ':'
        if (getline(ss, name, ':') && 
            getline(ss, lastName, ':') &&
            getline(ss, patronymic, ':') &&
            getline(ss, userLogin, ':') &&
            getline(ss, password, ':') &&
            getline(ss, address, ':') &&
            getline(ss, phone)) {
            
            // Сравниваем логин с текущим значением в строке
            if (userLogin == login) {
				in.close();  // Закрываем файл
                return true;   // Логин занят
            }
        }
    }

	in.close();  // Закрываем файл
    return false;  // Логин свободен
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
	phone = normalizePhoneNumber(phone); // приводим телефон к общему виду без "+7", заменяя его на "8"
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

	// ЗДЕСЬ МОЖНО ИСПОЛЬЗОВАТЬ ШИФРОВКУ ЛОГИНА И ПАРОЛЯ

	// Открываем файл для записи
	ofstream file(pathToUsersData, ios::app);
	if (!file.is_open()) {
		cout << "Unable to open file for writing.\n";
		return;
	}

	// Записываем данные пользователя в файл
	file << name << ":" << lastName << ":" << patronymic << ":"
		<< login << ":" << password << ":" << adress << ":" << phone << endl;

	file.close();
	cout << "Registration successful!" << endl;
}


// Функция для авторизации пользователя
bool UsersData::loginUser()
{
	int attemptCount = 0;  // Счётчик неудачных попыток
	string pathToUsersData = "Data.txt";
	string inputLogin, inputPassword;
	cout << "\t\t** Authorization **" << endl;

	// Запрашиваем логин и пароль
	cout << "Enter your login: ";
	cin >> inputLogin;
	// Проверяем, есть ли этот логин в файле
	if (!loginCheck(inputLogin, pathToUsersData)) {
		cout << "Login not found. Redirecting to registration..." << endl;
		registration();  // Переход к регистрации
		return false;  // Логин не найден
	}
	// Цикл для попыток ввода пароля (до 3 попыток)
	while (attemptCount < 3) {
		cout << "Enter your password: ";
		cin >> inputPassword;

		// Открываем файл для чтения
		ifstream in(pathToUsersData);
		if (!in.is_open()) {
			cout << "Unable to open file.\n";
			return false;
		}

		string line;
		bool loginFound = false;
		while (getline(in, line)) {  // Читаем файл построчно
			stringstream ss(line);  // Стрим для разделения строки
			string name, lastName, patronymic, userLogin, userPassword, address, phone;

			// Разделяем строку по символу ':'
			if (getline(ss, name, ':') &&
				getline(ss, lastName, ':') &&
				getline(ss, patronymic, ':') &&
				getline(ss, userLogin, ':') &&
				getline(ss, userPassword, ':') &&
				getline(ss, address, ':') &&
				getline(ss, phone)) {

				// Сравниваем логин и пароль
				if (userLogin == inputLogin && userPassword == inputPassword) {
					in.close();  // Закрываем файл
					cout << "Authorization successful!" << endl;
					return true;  // Успешная авторизация
				}
			}
		}

		in.close();  // Закрываем файл
		cout << "Invalid login or password. Try again." << endl;
		attemptCount++;  // Увеличиваем счётчик попыток

		if (attemptCount == 3) {
			cout << "You have entered wrong password 3 times." << endl;
			cout << "You will now be redirected to the registration page." << endl;
			return false;  // Завершаем функцию авторизации
			registration();  // Переходим к регистрации
		}
	}
}

UsersData::~UsersData()
{
}
