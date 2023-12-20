#include "file_oper.h"
#include <iostream>

void reader(ifstream& ist, vector<Planet>& planetVector) {
    while (!ist.eof()) {
        Planet planet;
        ist >> planet;
        planetVector.push_back(planet);
    }
}

void output(vector<Planet>& planetVector) {
    for (Planet& planet : planetVector) {
        cout << planet << endl;
    }
}
