#include "User.h"

User::User(string login, string password, string fio, string adress, string phoneNumber)
{
	this->login = login;
	this->password = password;
	this->fio = fio;
	this->adress = adress;
	this->phoneNumber = phoneNumber;
}

string User::getLogin()
{
	return this->login;
}

string User::getpassword()
{
	return this->password;
}

string User::getFio()
{
	return this->fio;
}

string User::getAdress()
{
	return this->adress;
}

string User::getPhoneNumber()
{
	return this->phoneNumber;
}

void User::setLogin(string login)
{
	this->login = login;
}

void User::setPassword(string password)
{
	this->password = password;
}

void User::setFio(string fio)
{
	this->fio = fio;
}

void User::setAdress(string adress)
{
	this->adress = adress;
}

void User::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
