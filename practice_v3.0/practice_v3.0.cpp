#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <fstream>
#include <string>
#include "date.h"
#include "planet.h"
#include "file_oper.h"
#include <vector>

using namespace std;

int main() {
    // Включаем утечки памяти
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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

    // Выводим информацию об утечках памяти
    _CrtDumpMemoryLeaks();

    return 0;
}