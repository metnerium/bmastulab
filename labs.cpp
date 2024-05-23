#include "labs.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int lab1() {
    double x, z, r, y;
    cout << "Введите значения x, z и r: ";
    cin >> x >> z >> r;

    y = sin(x - 5.1 * z) / log(x / r);

    cout << "y = " << y << endl;

    return 0;
}

int lab2() {
    for (int i = 1; i <= 500; i++) {
        int square = i * i;
        if (square % 5 == 0) {
            cout << "Число: " << i << ", квадрат: " << square << endl;
        }
    }

    return 0;
}

int lab5() {
    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    int count = 0;
    int firstHashIndex = -1;
    int nearestHashIndex = -1;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '#') {
            count++;
            if (firstHashIndex == -1) {
                firstHashIndex = i;
            } else {
                nearestHashIndex = i;
                break;
            }
        }
    }

    if (count == 0) {
        cout << "В строке нет символов '#'" << endl;
    } else if (count == 1) {
        cout << "В строке только один символ '#'" << endl;
    } else {
        cout << "Количество символов '#': " << count << endl;
        cout << "Адреса символов между первым и ближайшим символом '#':" << endl;
        for (int i = firstHashIndex + 1; i < nearestHashIndex; i++) {
            cout << (void*)(&str[i]) << endl;
        }
    }
    return 0;
}

namespace labs1{
    int lab() {
        int n;
        cout<<"Введите номер лабораторной 1 2 5: "<<endl;
        cin>>n;
        cin.ignore();
        switch (n) {
            case 1:
                lab1();
                break;
            case 2:
                lab2();
                break;
            case 5:
                lab5();
                break;
            default:
                cout<<"Неверный номер работы!";
                break;
        }
        return 0;
    }
}
