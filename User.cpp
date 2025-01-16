#include "User.h"

User::User(string login, Admin& admin) : UsersData(), admin(admin) {

}

void User::testing() {
    string testName;
    Test test;

    do {
        cout << "Enter the name of the test you want to take: ";
        cin >> testName;

        // ���������, ���������� �� ���� � ����� ���������
        if (!admin.isTestNameTaken(testName)) {
            cout << "Test with the name '" << testName << "' not found. Please try again." << endl;
        }
        else {
            test = loadTestFromFile(testName);  // ��������� ���� �� �����
        }
    } while (!admin.isTestNameTaken(testName)); // ��������� ����, ���� �� ������� ������������ ����

    if (test.questions.empty()) {
        cout << "No questions found for this test." << endl;
        return;  // ���� ������� �� ���������, ������� �� �������
    }

    // ���� ������� ������������
    vector<string> userAnswers;
    cout << "\nStarting test: " << test.name << " (" << test.category << ")\n" << endl;

    for (size_t i = 0; i < test.questions.size(); ++i) {
        string userAnswer;
        cout << "Question " << (i + 1) << ": " << test.questions[i] << endl;
        cout << "Enter your answer (y/n): ";
        cin.ignore(); // ������� ����� ����� ������
        getline(cin, userAnswer);
        userAnswers.push_back(userAnswer);
    }

    // ������ �����������
    int correctAnswers = 0;
    for (size_t i = 0; i < test.answers.size(); ++i) {
        // ���������� ����� ������������ � ���������� ������� (������ ������� ����)
        if (userAnswers[i] == test.answers[i].first) {
            correctAnswers++;
        }
    }

    // ������ �� 12-������� �����
    double maxScore = 12.0; // ������������ ����
    double score = (correctAnswers * maxScore) / test.questions.size();  // ������ �� ������ ���������� ���������� �������

    cout << "\nYour score: " << score << endl;

    // ������ ���������� � ����
    saveResultToFile(test.name, score);
}

Test User::loadTestFromFile(const string& testName) {
    ifstream testFile("Tests.txt");
    string line;
    Test test;

    if (!testFile.is_open()) {
        cout << "Error opening the test file." << endl;
        return test;
    }

    while (getline(testFile, line)) {
        stringstream ss(line);
        string category, name;
        vector<string> questions;
        vector<pair<string, string>> answers;

        // ������ ��������� � �������� �����
        getline(ss, category, ':');
        getline(ss, name, ':');
        test.category = category;
        test.name = name;

        // ������ �������� � �������, ���������� ����� "::"
        while (getline(ss, line, ':')) {
            // ������ ������
            string question = line;

            // ������ ���������� � ������������ �����
            getline(ss, line, ':');
            string correctAnswer = line;
            getline(ss, line, ':');
            string incorrectAnswer = line;

            questions.push_back(question);
            answers.push_back({ correctAnswer, incorrectAnswer });

            // ���� ��������� ������ � ������ - ��� ":", ������, �� ��������� � ���������� �������
            if (ss.peek() == ':') {
                ss.get();  // ���������� ���� ���������
            }
        }

        if (test.name == testName) {
            test.questions = questions;
            test.answers = answers;
            break;
        }
    }

    testFile.close();
    return test;
}

void User::saveResultToFile(const string& testName, int score)
{
    // ��������� ���� � ����� � ������������
    string resultFileName = getLogin() + "Results.txt";  // ��������� ��� ����� � ������������
    ofstream resultFile(resultFileName, ios::app);  // ��������� ���� ��� ���������� ������

    if (!resultFile.is_open()) {
        cout << "Error opening the results file." << endl;
        return;
    }

    // ���������� ��������� � ����
    resultFile << "Test: " << testName << ", Score: " << score << endl;

    resultFile.close();

    cout << "Your result has been saved in " << resultFileName << "!" << endl;
}

User::~User()
{

}
