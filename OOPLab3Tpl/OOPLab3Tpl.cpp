// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
using namespace std;

// Ваші файли загловки 
//
#include "Lab3Expaple.h"
int main()
{
    std::cout << "Lab #3  !\n";
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту
    while (true) {
        int task;

        cout << "\nSelect the number of exercise that you want to see\n\n";

        cin >> task;

        switch (task)
        {
        case 1: { Ex1(); break; }
        case 2: { Ex2(); break; }
        case 3: { Ex3(); break; } 
        default:
            break;
        }
    }

}

