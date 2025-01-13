#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include "Test.h"
#include "Admin.h"
#include <cstdlib>
using namespace std;
class User
{
private:
	string nameUser;
	string categoryUser;
public:
	/*User();*/
	User(string, string);
	string getNameUser();
	string getCategoryUser();
	void setNameUser(string);
	void setCategoryUser(string);
	void takeBreak();
	Test goTest();

};

