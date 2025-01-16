#include "Admin.h"

Admin::Admin()
{
}

void Admin::createNewUser()
{
    registration();
}

void Admin::deleteUser()
{
    string userLogin;
    int counter = 0;
    cout << "Login of the user who must to be deleted: ";
    cin >> userLogin;

    // �������� �� ������� ������������
    if (!loginCheck(userLogin, getPathToUsersData())) {
        cout << "User not found." << endl;
        return;
    }
    else {
        ifstream in(getPathToUsersData());  // ��������� ���� ��� ������
        ofstream out("temp_users.txt");     // ��������� ��������� ���� ��� ������
        string line;
        bool userFound = false;  // ����, ������� �������, ����� �� �� ������������

        // ������ ����� �� �����
        while (getline(in, line)) {
            stringstream ss(line);
            string name, lastName, patronymic, login, password, address, phone;

            // ���������� ������ �� ����������� ':'
            if (getline(ss, name, ':') &&
                getline(ss, lastName, ':') &&
                getline(ss, patronymic, ':') &&
                getline(ss, login, ':') &&
                getline(ss, password, ':') &&
                getline(ss, address, ':') &&
                getline(ss, phone))
            {
                // ���� ����� ������, ���������� ��� ������ (�� ���������� � ����� ����)
                if (userLogin == login) {
                    userFound = true;
                    continue;  // ���������� ������� ������
                }
            }

            // ���� ����� �� ������, ���������� ������ � ����� ����
            out << line << endl;
            counter++;
        }

        // ��������� �����
        in.close();
        out.close();

        // ���� ������������ ��� ������, �������� ������������ ���� ���������
        if (userFound) {
            remove(getPathToUsersData().c_str());  // ������� ������ ����
            rename("temp_users.txt", getPathToUsersData().c_str());  // ��������������� ��������� ���� � ������������
            cout << "User with login " << userLogin << " deleted successfully!" << endl;
        }
        else {
            cout << "User with login " << userLogin << " not found." << endl;
        }
    }
}

bool Admin::isTestNameTaken(const string& testName)
{
    // ��������� ���� "Tests.txt" � ������ ������
    ifstream testFile("Tests.txt");

    if (!testFile.is_open()) {
        return false;  // ���� ���� �� ���������� ��� �� ������, ���������� false (���� �� ������)
    }

    string line;
    while (getline(testFile, line)) {
        // ��������� ������ �� ����� �� ������� ":"
        stringstream ss(line);
        string category, existingTestName, rest;
        getline(ss, category, ':');
        getline(ss, existingTestName, ':');

        // ���� ��� ����� ���������, ������, ��� ������
        if (existingTestName == testName) {
            testFile.close();
            return true;
        }
    }

    testFile.close();
    return false;  // ��� �� �������
}

void Admin::createTest() {
    vector<string> validCategories = { "Physics", "Math", "Law", "Programming", "Geography", "Other" };

    string category;
    bool validCategory = false;

    do {
        // ������ ��������� �����
        cout << "Enter the category of the test (Physics, Math, Law, Programming, Geography, Other): ";
        cin >> category;

        validCategory = false;
        for (const string& validCat : validCategories) {
            if (category == validCat) {
                validCategory = true;
                break;
            }
        }

        if (!validCategory) {
            cout << "Invalid category! Please choose one of the following: Physics, Math, Law, Programming, Geography, Other." << endl;
        }

    } while (!validCategory); // ���������, ���� ��������� �� ����� ������

    // ������ �������� ����� � ���������, ������ �� ���
    string testName;
    bool nameTaken = false;
    do {
        cout << "Enter the name of the test: ";
        cin >> testName;

        // ���������, ������ �� ��������
        nameTaken = isTestNameTaken(testName);
        if (nameTaken) {
            cout << "Test name '" << testName << "' is already taken. Please choose another name." << endl;
        }

    } while (nameTaken);  // ���������, ���� �������� �� ����� ����������

    // ������� ������ �����
    Test test;
    test.category = category;
    test.name = testName;

    // ������ ���������� ��������
    int numQuestions = 0;
    do {
        cout << "How many questions would you like to add? (Max 12): ";
        cin >> numQuestions;

        if (numQuestions < 1 || numQuestions > 12) {
            cout << "You can add between 1 and 12 questions only." << endl;
        }
    } while (numQuestions < 1 || numQuestions > 12);

    if (numQuestions != 1) {
        cout << "Attention!\nIf your test has 2 or more questions, press the spacebar before entering the text\nof the second and subsequent questions to avoid errors when saving your questions." << endl;
    }

    // ��������� ������� � ������
    for (int i = 0; i < numQuestions; ++i) {
        string question, correctAnswer, incorrectAnswer;

        cout << "Enter question " << (i + 1) << ": ";
        cin.ignore();  // ���������� ������ ����� ������ ����� ������ �������
        getline(cin, question);

        cout << "Enter the correct answer: ";
        getline(cin, correctAnswer);

        cout << "Enter the incorrect answer: ";
        getline(cin, incorrectAnswer);

        // ��������� ������ � ������ � ������ �����
        test.questions.push_back(question);
        test.answers.push_back({ correctAnswer, incorrectAnswer });
    }

    // ��������� ���� � ����
    test.saveToFile("Tests.txt");

    cout << "Test created successfully and saved to Tests.txt" << endl;
}

Admin::~Admin()
{
}
