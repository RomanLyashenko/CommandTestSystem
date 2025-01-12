#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test {
	string category;
	string name;
	vector<string> questions;
	vector<vector<string>> answers;
	vector<int> correctAnswers;
public:
	Test(string category, string name, vector<string> questions, vector<vector<string>> answers, vector<int> correctAnswers);
	void print();
	~Test();
};
