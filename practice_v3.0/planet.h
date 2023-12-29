#pragma once
#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <string>
#include "date.h"
#include <exception>

using namespace std;

struct Planet {

	string name;
	Date date;
	double radius;

	Planet(); 
	Planet(const string& planetName, const Date& planetDate, double planetRadius); 

};

std::ostream& operator<< (std::ostream& os, Planet& planet);
std::istream& operator>> (std::istream& is, Planet& planet);


#endif // !PLANET_H