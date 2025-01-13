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
	string getCategory();
	string getName();
	vector<string> getQuestions();
	vector<vector<string>> getAnswers();
	vector<int> getCorrectAnswers();
	void print();
	~Test();
};

