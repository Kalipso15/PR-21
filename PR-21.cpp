#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
using namespace std;

bool isBinary(const string& str) {
    for (char ch : str) {
        if (ch != '0' && ch != '1') {
            return false;
        }
    }
    return true;
}

int binaryToDecimal(const string& str) {
    int decimal = 0;
    int power = 0;
    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, " Ukrainian");

    string input;
    cout << "Введіть рядок символів: ";
    getline(cin, input);

    string number;
    for (char ch : input) {
        if (ch == '0' || ch == '1') {
            number += ch;
        }
    }

    // Remove spaces
    number.erase(remove(number.begin(), number.end(), ' '), number.end());

    // Remove characters after the dot
    size_t dotPosition = number.find('.');
    if (dotPosition != string::npos) {
        number = number.substr(0, dotPosition);
    }

    if (isBinary(number)) {
        if (number.length() > 1) {
            int decimalNumber = binaryToDecimal(number);
            cout << "Десяткове представлення числа: " << decimalNumber << endl;
        }
        else {
            cout << "Введене число є недопустимим." << endl;
        }
    }
    else {
        cout << "Рядок не є представленням числа у двійковому коді." << endl;
    }

    return 0;
}
