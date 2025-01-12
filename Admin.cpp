#include "Admin.h"

Admin::Admin(string login, string pass)
{
    this->login = login;
    this->pass = pass;
}


Test Admin::createTest()
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
        questions.push_back(question);
        vector<string> answers;
        for (int j = 0; j < 3; j++) {
            cout << "Enter answer " << j + 1 << ": ";
            cin >> answer;
            answers.push_back(answer);
        }
        answersMatrix.push_back(answers);
        cout << "Enter correct answer: ";
        cin >> correctAnswer;
        correctAnswers.push_back(correctAnswer);
    }
    Test newTest(category, name, questions, answersMatrix, correctAnswers);
    return newTest;
}
