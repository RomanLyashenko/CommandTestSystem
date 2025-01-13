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

Test User::createTest()
{
    string category;
    string name;
    string question;
    string answer;
    int correctAnswer;
    vector<string> questions;
    int questionsNum;
    vector<vector<string>> answersMatrix;
    vector<int> correctAnswers;
    vector<string> answers;
    cout << "Enter category: ";
    cin >> category;
    cout << "Enter test name: ";
    cin >> name;
    cout << "Enter amount of questions: ";
    cin >> questionsNum;
    cout << questions.size();
    for (int i = 0; i < questionsNum; i++) {
        cout << "Enter question " << i + 1 << ": ";
        cin >> question;
        questions.push_back(question); // вопросы
        //vector<string> answers;
        for (int j = 0; j < 3; j++) {
            cout << "Enter answer " << j + 1 << ": ";
            cin >> answer;
            answers.push_back(answer); // варианты ответов
        }
        answersMatrix.push_back(answers);
        cout << "Enter correct answer: ";
        cin >> correctAnswer;
        correctAnswers.push_back(correctAnswer); // правильные ответы
    }
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
    Test newTest(category, name, questions, answersMatrix, correctAnswers);
    return newTest;
}
