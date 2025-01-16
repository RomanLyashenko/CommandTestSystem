#pragma once
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include "Admin.h"

class Test {
public:
    std::string category; // ��������� �����
    std::string name;     // �������� �����
    std::vector<std::string> questions; // ������� �����
    std::vector<std::pair<std::string, std::string>> answers; // ������ (������ - ����������, ������ - ������������)

    // ����� ��� ������ ����� � ����
    void saveToFile(const std::string& filename);
};