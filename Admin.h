#pragma once
#include <iostream>
#include <string>
using namespace std;

class Admin
{
private:
	string login;
	string pass;
public:
	Admin(string login, string pass);
	string getLogin();
	void setLogin(string login);
	void setPass(string pass);
	string getPass();

	void changePass();
	void changeLogin();
	void menuAdmin();
	~Admin();
};

