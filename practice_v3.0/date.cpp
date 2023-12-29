#include <iostream>
#include <fstream>
#include "date.h"
#include <exception>

using namespace std;


bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int dd, int mm, int yyyy)
{
    if (mm < 1 || mm > 12) {
        throw std::invalid_argument("invalid month");
    }
    if (yyyy < 0) {
        throw std::invalid_argument("invalid year");
    }
    if (dd < 1 || dd > 31) {
        throw std::invalid_argument("invalid day");
    }
    if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && (dd < 1 || dd > 31)) {
        throw std::invalid_argument("invalid day in month");
    }
    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && (dd < 1 || dd > 30)) {
        throw std::invalid_argument("invalid day in month");
    }

    day = dd;
    month = mm;
    year = yyyy;
}


std::istream& operator>>(std::istream& is, Date& date) {
    try {
        is >> date.year;
        is.get();
        is >> date.month;
        is.get();
        is >> date.day;

        if (date.month == 2 && date.day == 29 && !IsLeapYear(date.year)) {
            throw std::runtime_error("Invalid date: Not a leap year, but day is 29 in February.");
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error while reading Date data: " << e.what() << std::endl;
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, Date& date) {
    os << date.year << "." << date.month << "." << date.day;
    return os;
}