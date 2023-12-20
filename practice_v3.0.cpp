#include <iostream>
#include <fstream>
#include <string>
#include "date.h"
#include "planet.h"
#include "file_oper.h"
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    string path = "test.txt";
    ifstream fs;

    try {
        fs.open(path);
        if (!fs.is_open()) {
            throw runtime_error("Unable to open file: " + path);
        }

        vector<Planet> planetVector;
        reader(fs, planetVector);
        output(planetVector);

    }
    catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}