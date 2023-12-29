#include <iostream>
#include <iomanip>
#include "planet.h"
#include <exception>
#include "date.h"

using namespace std;

Planet::Planet() : radius(0) {}

//Planet::Planet(string& planetName, Date& planetDate, double planetRadius) : name(planetName), date(planetDate), radius(planetRadius)
//{
//    if (radius < 0) {
//        throw std::invalid_argument("Invalid radius");
//    }
//
//    if (name.find_first_of(".,;:!?'\"") != string::npos) {
//        throw std::invalid_argument("Invalid name");
//    }
//
//    if (name.find_first_of("1234567890'\"") != string::npos) {
//        throw std::invalid_argument("Invalid name");
//    }
//}

Planet::Planet(const string& planetName, const Date& planetDate, double planetRadius) : name(planetName), date(planetDate), radius(planetRadius)
{
    if (radius < 0) {
        throw std::invalid_argument("Invalid radius");
    }

    if (name.find_first_of(".,;:!?'\"1234567890") != string::npos) {
        throw std::invalid_argument("Invalid name");
    }
}


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