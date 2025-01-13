#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Test.h"
#include "User.h"

using namespace std;

class Admin
{
private:
	string login;
	string pass;
	vector<Test> arrTestAdmin;
	vector<User> arrUserAdmin;
	
public:
	Admin(string login, string pass);
	string getLogin();
	void setLogin(string login);
	void setPass(string pass);
	string getPass();
	Test createTest();
	void deleteTest();
	User addUser();
	void deleteUser();
	void changePass();
	void changeLogin();
	void menuAdmin();


	~Admin();
};


