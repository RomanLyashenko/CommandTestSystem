#include "Admin.h"

Admin::Admin(string login, string pass)
{
    this->login = login;
    this->pass = pass;
}

string Admin::getLogin()
{
    return this->login;
}

void Admin::setLogin(string login)
{
    this->login = login;
}

void Admin::setPass(string pass)
{
    this->pass = pass;
}

string Admin::getPass()
{
    return this->pass;
}

void Admin::changePass()
{
    string newPass;
    cout << "enter new pass: ";
    cin >> newPass;
    cout << endl;
    if (newPass == this->pass) {
        cout << "the passwords are the same" << endl;
    }
    else {
        this->pass = newPass;
        cout << "you have successfully changed your password" << endl;
    }
}

void Admin::changeLogin()
{
    string newLogin;
    cout << "enter new login: ";
    cin >> newLogin;
    cout << endl;
    if (newLogin == this->login) {
        cout << "the login are the same" << endl;
    }
    else {
        this->login = newLogin;
        cout << "you have successfully changed your password" << endl;
    }
}

void Admin::menuAdmin()
{
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl << "Меню:" << endl;
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl << "1. Управление пользователями";
    cout << endl << "2. Управление тестами:";
    cout << endl << "3. Создание тестов";
    cout << endl << "4. Изменение тестов";
    cout << endl << "5. Удаление тестов";
    cout << endl << "6. Импорт";
    cout << endl << "7. Экспорт";
    cout << endl << "8. Просмотр статистики";
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
}
    
Admin::~Admin()
{
}
