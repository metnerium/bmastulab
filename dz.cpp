#include "dz.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


bool isPalindrome(int num) {
    string str = to_string(num);
    string rev = str;
    reverse(rev.begin(), rev.end());
    return str == rev;
}

int dz1() {
    int n;
    cout << "Введите число n: ";
    cin >> n;

    int count = 0;
    cout << "Числа-палиндромы, квадраты которых также являются палиндромами:" << endl;

    for (int i = 0; i <= n; i++) {
        if (isPalindrome(i)) {
            int square = i * i;
            if (isPalindrome(square)) {
                cout << i << " -> " << square << endl;
                count++;
            }
        }
    }

    cout << "Количество найденных чисел: " << count << endl;

    return 0;
}



int dz2() {
    vector<string> lines;
    string line;
    cout << "Введите последовательность строк (для завершения введите пустую строку):" << endl;

    while (getline(cin, line) && !line.empty()) {
        lines.push_back(line);
    }

    vector<pair<string, string>> replacements;
    cout << "Введите пары слов для замены (для завершения введите пустую строку):" << endl;

    while (getline(cin, line) && !line.empty()) {
        istringstream iss(line);
        string replaced, replacement;
        iss >> replaced >> replacement;
        replacements.emplace_back(replaced, replacement);
    }

    cout << "Исходная последовательность строк:" << endl;
    for (const string& line : lines) {
        cout << line << endl;
    }

    cout << "Скорректированная последовательность строк:" << endl;
    for (string& line : lines) {
        for (const auto& pair : replacements) {
            const string& replaced = pair.first;
            const string& replacement = pair.second;
            size_t pos = 0;
            while ((pos = line.find(replaced, pos)) != string::npos) {
                line.replace(pos, replaced.length(), replacement);
                pos += replacement.length();
            }
        }
        cout << line << endl;
    }

    return 0;
}


namespace dz{
    int tasks() {
        int n;
        cout<<"Введите номер задачи 1 2"<<endl;
        cin>>n;
        cin.ignore();
        switch (n) {
            case 1:
                dz1();
                break;
            case 2:
                dz2();
                break;
            default:
                cout<<"Неверный номер задачи!";
                break;

        }
        return 0;
    }

}