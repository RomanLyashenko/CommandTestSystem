#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Test.h"
#include "Admin.h"
using namespace std;
int main()
{
	vector<string>questions = { "1", "2", "3" };
	vector<vector<string>> answers;
	vector<int>correctAnswer = { 1, 2, 3 };
	Test test1("math", "discret math", questions, answers, correctAnswer);
	User user("math", "discret math");
	user.goTest();
	//string category;
	//string name;
	//cout << "Enter the test category: ";
	//cin >> category
	//cout << "Ente;r the test name: ";
	//cout << endl;
	//cin >> name;
	//cout << endl;
	
}
