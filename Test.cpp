#include "Test.h"

Test::Test(string category, string name, vector<string> questions, vector<vector<string>> answers, vector<int> correctAnswers)
{
	this->category = category;
	this->name = name;
	this->questions = questions;
	this->answers = answers;
	this->correctAnswers = correctAnswers;
}

string Test::getCategory()
{
	return this->category;
}

string Test::getName()
{
	return this->name;
}

vector<string> Test::getQuestions()
{
	return this->questions;
}

vector<vector<string>> Test::getAnswers()
{
	return this->answers;
}

vector<int> Test::getCorrectAnswers()
{
	return this->correctAnswers;
}

void Test::print()
{
	cout << "Test category: " << category << endl;
	cout << "Test name: " << name << endl;
	for (int i = 0; i < questions.size(); i++) {
		cout << "Question " << i + 1 << ": " << questions[i] << endl;
		for (int j = 0; j < 3; j++) {
			cout << j + 1 << " - " << answers[i][j];
			cout << endl;
		}
		cout << "Correct answer: " << correctAnswers[i] << endl;
	}
}

Test::~Test()
{
}
