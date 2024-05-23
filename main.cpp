#include <iostream>
#include "labs.h"
#include "dz.h"

using namespace std;
int main(){
    int n;
    cout<<"1. Лабораторные работы"<<endl;
    cout<<"2. Домашние задания"<<endl;
    cin>>n;
    switch (n) {
        case 1:
            labs1::lab();
            break;
        case 2:
            dz::tasks();
            break;
        default:
            cout<<"Неверный выбор!";
            break;
    }
}