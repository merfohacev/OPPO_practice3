#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

    Date() : day(0), month(0), year(0) {}

   
};

istream& operator >> (istream& ist, Date& date);
ostream& operator << (ostream& ost, Date& date);


#endif // !DATE_H
