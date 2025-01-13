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

User Admin::addUser() {
    string categoryUser;
    string nameUser;
    cout << "enter name user: ";
    cin >> nameUser;
    cout << endl;
    cout << "enter category user: ";
    cin >> categoryUser;
    cout << endl;

    User newUser(categoryUser, nameUser);
    return newUser;
}

void Admin::deleteUser()
{
    if (this->arrUserAdmin.empty()) {
        cout << "you don't have tests, add user them" << endl;
    }
    else {
        for (auto item : arrUserAdmin) {
            int numberTest = 1;
            cout << "user number: " << numberTest << endl;
            cout << "name user: " << item.getNameUser() << endl;
            cout << "name category: " << item.getCategoryUser() << endl << endl;
            numberTest++;
        }
        int choiseDelete;
        cout << "enter the number of the user you want to delete: ";
        cin >> choiseDelete;
        if (choiseDelete > 0 && choiseDelete <= arrUserAdmin.size()) {
            arrUserAdmin.erase(arrUserAdmin.begin() + (choiseDelete - 1));
            cout << endl << "user is delete" << endl;
        }
        else {
            cout << "no correct" << endl;
        }
    }
}

void Admin::deleteTest() {
    if (this->arrTestAdmin.empty()) {
        cout << "you don't have tests, add test them" << endl;
    }
    else {
        for (auto item : arrTestAdmin) {
            int numberTest = 1;
            cout << "test number: " << numberTest << endl;
            cout << "category test: " << item.getCategory() << endl;
            cout << "name test: " << item.getName() << endl << endl;
            numberTest++;
        }
        int choiseDelete;
        cout << "enter the number of the test you want to delete: ";
        cin >> choiseDelete;
        if (choiseDelete > 0 && choiseDelete <= arrTestAdmin.size()) {
            arrTestAdmin.erase(arrTestAdmin.begin() + (choiseDelete - 1));
            cout << endl << "test is delete" << endl;
        }
        else {
            cout << "no correct" << endl;
        }
    }
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

void Admin::importTest()
{
    int questionCounter = 0;
    string path;
    string line;
    string importQuestion = "";
    string importCategory = "";
    string importName = "";
    string importAnswer = "";
    vector<string> importQuestions;
    vector<vector<string>> importAnswersMatrix;
    vector<string> importAnswers;
    vector<int> importCorrectAnswers;
    cout << "In what file you want test to be imported: ";
    cin >> path;
    ifstream in;
    in.open(path);
    if (in.is_open()) {
        while (getline(in, line)) {
            for (int i = 0; line[i] != '\0'; i++) {
                if (line[i] == 'e' && line[i + 1] == ':') {
                    for (int j = i + 2; line[j] != '\0'; j++) {
                        importName += line[j];
                    }
                    break;
                }
                if (line[i] == 'y' && line[i + 1] == ':') {
                    for (int j = i + 2; line[j] != '\0'; j++) {
                        importCategory += line[j];
                    }
                    break;
                }
                if (line[0] == 'Q') {
                    questionCounter++;
                    importQuestion = "";
                    for (int j = 0; line[j] != '\0'; j++) {
                        if (line[j] == ':') {
                            for (int k = j + 1; line[k] != '\0'; k++) {
                                importQuestion += line[k];
                            }
                            importQuestions.push_back(importQuestion);
                            break;
                        }
                    }
                    break;
                }
                if (isdigit(line[0])) {
                    importAnswer = "";
                    for (int j = 2; line[j] != '\0'; j++) {
                        importAnswer += line[j];
                    }
                    importAnswers.push_back(importAnswer);
                    if (importAnswers.size() == 3) {
                        importAnswersMatrix.push_back(importAnswers);
                        importAnswers.clear();
                    }
                    break;
                }
                if (line[i] == 'r' && line[i + 1] == ':') {
                    importCorrectAnswers.push_back(line[i + 2] - 48);
                    break;
                }
            }
        }
        cout << "Test from file added to your tests succesfully!" << endl;
        Test importTest(importCategory, importName, importQuestions, importAnswersMatrix, importCorrectAnswers);
        this->arrTestAdmin.push_back(importTest);
    }
    else {
        cout << "file is not existing;" << endl;
    }
}

void Admin::exportTest()
{
    for (auto item : arrTestAdmin) {
        int numberTest = 1;
        cout << "test number: " << numberTest << endl;
        cout << "category test: " << item.getCategory() << endl;
        cout << "name test: " << item.getName() << endl << endl;
        numberTest++;
    }
    int exportTestNum;
    cout << "Which test you want to export? ";
    cin >> exportTestNum;
    exportTestNum -= 1;
    vector<string> exportQuestions = this->arrTestAdmin[exportTestNum].getQuestions();
    vector<vector<string>> exportAnswers = this->arrTestAdmin[exportTestNum].getAnswers();
    vector<int> exportCorrectAnswers = this->arrTestAdmin[exportTestNum].getCorrectAnswers();
    string path = "out.txt";
    ofstream out;
    out.open(path);
    out << "Test name:" << this->arrTestAdmin[exportTestNum].getName() << endl;
    out << "Test category:" << this->arrTestAdmin[exportTestNum].getCategory() << endl;
    for (int i = 0; i < exportQuestions.size(); i++) {
        out << "Question " << i + 1 << ":" << exportQuestions[i] << endl;
        for (int j = 0; j < 3; j++) {
            out << j + 1 << ":" << exportAnswers[i][j];
            out << endl;
        }
        out << "Correct answer:" << exportCorrectAnswers[i] << endl;
    }

}


void Admin::menuAdmin()
{
    int choise;
    while (true) {
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
        system("cls");
        switch (choise) {
        case 1:
            arrTestAdmin.push_back(createTest());
            break;
        case 2:
            deleteTest();
            break;
        case 3:
            arrUserAdmin.push_back(addUser());
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            importTest();
            break;
        case 6:
            exportTest();
            break;
        case 8:
            changeLogin();
            break;
        case 9:
            changePass();
            break;
        }
    }
    

}

Admin::~Admin()
{
}
