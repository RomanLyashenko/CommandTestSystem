#include <iostream>
using namespace std;

// Тот, кто занимается аутентификацией, скопируй эти функции и испьзуй при выводе логина и пароля

void toCipherWord(string word, string key) {
    for (int i = 0; key[i] != '\0'; i++) {
        key[i] = tolower(key[i]);
    }
    int counter = 0;
    string wordWithKey = word;
    string sipheredWord = word;
    for (int i = 0; word[i] != '\0'; i++) {
        if (key[counter] == '\0') {
            counter = 0;
        }
        wordWithKey[i] = key[counter++];
    }
    int numOfLetter;
    for (int i = 0; word[i] != '\0'; i++) {
        numOfLetter = word[i];
        if (isupper(word[i])) {
            numOfLetter = word[i] + (wordWithKey[i] - 96);
            if (numOfLetter > 90) {
                numOfLetter -= 26;
            }
        }
        else if (islower(word[i])) {
            numOfLetter = word[i] + (wordWithKey[i] - 96);
            if (numOfLetter > 122) {
                numOfLetter -= 26;
            }
        }
        else if (isdigit(word[i])) {
            numOfLetter = word[i] + (wordWithKey[i] - 96);
            while (numOfLetter > 57) {
                numOfLetter -= 10;
            }
        }
        sipheredWord[i] = numOfLetter;
    }
    cout << sipheredWord << endl;
}

void toCipher(string password, string login) {
    string logKey;
    cout << "Enter key word to cipher for login: ";
    cin >> logKey;
    toCipherWord(login, logKey);
    string passKey;
    cout << "Enter key word to cipher for password: ";
    cin >> passKey;
    toCipherWord(password, passKey);
}

