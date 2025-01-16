#include "User.h"

User::User()
{
}

User::User(string categoryUser, string nameUser)
{
	this->categoryUser = categoryUser;
	this->nameUser = nameUser;
}

string User::getNameUser()
{
	return this->nameUser;
}

string User::getCategoryUser()
{
	return this->categoryUser;
}

void User::setNameUser(string nameUser)
{
	this->nameUser = nameUser;
}

void User::setCategoryUser(string categoryUser)  
{
	this->categoryUser = categoryUser;
}

void User::goTest()
{
    bool goTest;
    cout << "Press 1 to pass the test: ";
    cin >> goTest;
    cout << endl;
    vector <int> answersUser;
    int answerUser;
    int goodmark = 0;
    int badmark = 0;
    string answer;
    string question;
    vector<string>questions;
    int questionsNum;
    vector<string>answers;
    int correctAnswer;
    cout << "Enter amount of questions: ";
    cin >> questionsNum;
    for (int i = 0; i < questionsNum; i++) {
        cout << "Enter question " << i + 1 << ": ";
        cin >> question;
        questions.push_back(question);
        for (int j = 0; j < 3; j++) {
            cout << "Enter answer " << j + 1 << ": ";
            cin >> answer;
            answers.push_back(answer);
        }
    }
    for (int i = 0; i < questionsNum; i++) {
        cout << "Enter correct answer for " << i + 1 << ": ";
        cin >> correctAnswer;
    }
    for (int i = 0; i < questions.size(); i++) {
        for (auto item : questions) {
            cout << endl;
            cout << "Question: " << i + 1 << ":" << endl;
            cout << item;
            cout << endl;
        }
        cout << endl;
        cout << "Enter answer for " << i + 1 << " question: " << endl;
        cout << "Choice: " << endl;
        for (auto item : answers) {
            cout << item << " | ";
        }
        cout << endl;
        cin >> answerUser;
        answersUser.push_back(answerUser);
        if (answerUser == correctAnswer) {
            cout << "The answer is correct" << endl;
            goodmark++;
        }
        else {
            cout << "The answer is incorrect" << endl;
            badmark++;
        }
    }
    float procentCorrectAnswer = (goodmark / questions.size()) * 100;
    cout << endl;
    cout << "The number of correct answers: " << goodmark << endl;
    cout << "The number of incorrect answers: " << badmark << endl;
}

//User::~User()
//{
//
//}
