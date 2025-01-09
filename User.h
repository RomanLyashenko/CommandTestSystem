#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
using namespace std;
class User
{
private:
	string login;
	string password;
	string fio;
	string adress;
	string phoneNumber;
public:
	User(string, string, string, string, string);
	string getLogin();
	string getpassword();
	string getFio();
	string getAdress();
	string getPhoneNumber();
	void setLogin(string);
	void setPassword(string);
	void setFio(string);
	void setAdress(string);
	void setPhoneNumber(string);


};

