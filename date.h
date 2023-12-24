#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//struct Date {
//
//    int day;
//    int month;
//    int year;
//
//    Date() {
//        day, month, year = 0;
//    }
//};

struct Date {
    int day;
    int month;
    int year;

    Date() : day(0), month(0), year(0) {}

    // Конструктор для поддержки инициализации из списка
    /*Date(std::initializer_list<int> list) {
        if (list.size() == 3) {
            auto it = list.begin();
            year = *it;
            ++it;
            month = *it;
            ++it;
            day = *it;
        }
        else {
            throw std::invalid_argument("Initializer list must contain three elements.");
        }
    }*/
};

istream& operator >> (istream& ist, Date& date);
ostream& operator << (ostream& ost, Date& date);


#endif // !DATE_H