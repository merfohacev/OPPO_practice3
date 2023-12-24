#include <iostream>
#include <iomanip>
#include "planet.h"
#include <exception>
#include "date.h"

using namespace std;




ostream& operator<<(ostream& os, Planet& planet) {
    os << "Название: " << setw(7) << planet.name << " | " << "Дата: " << planet.date << " | " << "Радиус: " << planet.radius;
    return os;
}

istream& operator>>(istream& is, Planet& planet) {
    try {
        is >> planet.name;
        planet.name = planet.name.substr(1, planet.name.size() - 2);
        is >> planet.date;
        is >> planet.radius;
    }
    catch (const std::exception& e) {
        // Обработка ошибок чтения данных
        std::cerr << "Error while reading Planet data: " << e.what() << std::endl;
    }

    return is;
}