#include "User.h"

User::User()
{
}
//
//User::User(string categoryUser, string nameUser)
//{
//	this->categoryUser = categoryUser;
//	this->nameUser = nameUser;
//}
//
//string User::getNameUser()
//{
//	return this->nameUser;
//}
//
//string User::getCategoryUser()
//{
//	return this->categoryUser;
//}
//
//void User::setNameUser(string nameUser)
//{
//	this->nameUser = nameUser;
//}
//
//void User::setCategoryUser(string categoryUser)  
//{
//	this->categoryUser = categoryUser;
//}

Test User::goTest(string category, string name, vector<Test> testUser)
{
    cout << endl;
    bool goTest;
    cout << "Press 1 to pass the test: ";
    cin >> goTest;
    cout << endl;
    system("cls"); // очистка консоли
    vector <int> answersUser;
    int answerUser;
    int goodmark = 0;
    int badmark = 0;
    for (int i = 0; i < questions.size(); i++) {
        for (auto item : questions) {
            cout << endl;
            cout << "Questions: " << endl;
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
    cout << endl;
    cout << "The number of correct answers: " << goodmark << endl;
    cout << "The number of incorrect answers: " << badmark << endl;
}
