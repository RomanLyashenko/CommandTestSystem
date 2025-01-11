#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Test.h"

using namespace std;

class Admin
{
private:
	string login;
	string pass;
	vector<Test> arrTestAdmin;
	
public:
	Admin(string login, string pass);
	string getLogin();
	void setLogin(string login);
	void setPass(string pass);
	string getPass();
	Test createTest();
	Test deleteTest();
	void changePass();
	void changeLogin();
	void menuAdmin();


	~Admin();
};


