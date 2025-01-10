#include "Admin.h"

Admin::Admin(string login, string pass)
{
    this->login = login;
    this->pass = pass;
}

string Admin::getLogin()
{
    return this->login;
}

void Admin::setLogin(string login)
{
    this->login = login;
}

void Admin::setPass(string pass)
{
    this->pass = pass;
}

string Admin::getPass()
{
    return this->pass;
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

void Admin::changePass()
{
    string newPass;
    cout << "enter new pass: ";
    cin >> newPass;
    cout << endl;
    if (newPass == this->pass) {
        cout << "the passwords are the same" << endl;
    }
    else {
        this->pass = newPass;
        cout << "you have successfully changed your password" << endl;
    }
}

void Admin::changeLogin()
{
    string newLogin;
    cout << "enter new login: ";
    cin >> newLogin;
    cout << endl;
    if (newLogin == this->login) {
        cout << "the login are the same" << endl;
    }
    else {
        this->login = newLogin;
        cout << "you have successfully changed your password" << endl;
    }
}

void Admin::menuAdmin()
{
    int choise;
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl << "Menu:" << endl;
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl << "1. Create Test";
    cout << endl << "2. Delete Test:";
    cout << endl << "3. Add user";
    cout << endl << "4. Delete user";
    cout << endl << "5. Import test";
    cout << endl << "6. Export test";
    cout << endl << "7. Watch statistic";
    cout << endl << "8. Change login";
    cout << endl << "9. Change password";
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
    cin >> choise;
    switch (choise) {
    case 1:
        createTest();
        break;

    }
}

Admin::~Admin()
{
}
