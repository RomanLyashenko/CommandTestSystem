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
    cout << endl << "����:" << endl;
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl << "1. ���������� ��������������";
    cout << endl << "2. ���������� �������:";
    cout << endl << "3. �������� ������";
    cout << endl << "4. ��������� ������";
    cout << endl << "5. �������� ������";
    cout << endl << "6. ������";
    cout << endl << "7. �������";
    cout << endl << "8. �������� ����������";
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
}
    
Admin::~Admin()
{
}
