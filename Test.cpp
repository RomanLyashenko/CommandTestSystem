#include "Test.h"
#include <fstream>
#include <iostream>

void Test::saveToFile(const std::string& filename) {
    std::ofstream testFile(filename, std::ios::app);
    if (!testFile.is_open()) {
        std::cout << "Error opening the test file." << std::endl;
        return;
    }

    // ���������� ��������� � �������� �����
    testFile << category << ":" << name << ":";

    // ���������� ������� � ������
    for (size_t i = 0; i < questions.size(); ++i) {
        testFile << questions[i] << ":"
            << answers[i].first << ":"
            << answers[i].second;

        if (i < questions.size() - 1) {
            testFile << "::";  // ����������� ��� ��������
        }
    }

    // ������� �� ����� ������ ����� ������ ���� �������� � �������
    testFile << std::endl;
    testFile.close();
}