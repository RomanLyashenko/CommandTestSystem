#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Test.h"

class Admin
{
private:
	string login;
	string pass;
public:
	Admin(string login, string pass);
	//string getLogin();
	//void setLogin(string login);
	//void setPass(string pass);
	//string getPass();
	Test createTest();
	/*void changePass();
	void changeLogin();
	void menuAdmin();
	~Admin();*/
};


