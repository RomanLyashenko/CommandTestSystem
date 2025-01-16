#pragma once
using namespace std;
#include <string>
#include <vector>
#include "UsersData.h"
#include <fstream>
#include "Test.h"
#include "Admin.h"

class User : public UsersData
{
private:
	Admin& admin;
public:
	User(string login, Admin& admin); // ����������� � �����������
	void testing();
	Test loadTestFromFile(const std::string& testName); // ������ ����� �� �����
	void saveResultToFile(const string& testName, int score); // ���������� ����������
	~User();
};

