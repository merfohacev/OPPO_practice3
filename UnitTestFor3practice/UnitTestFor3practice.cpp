#include "pch.h"
#include "CppUnitTest.h"
#include <exception>
#include "../practice_v3.0/date.h"
#include "../practice_v3.0/planet.h"
#include "../practice_v3.0/file_oper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFor3practice
{
	TEST_CLASS(FileOperationsTest) {
public:

    TEST_METHOD(FileOperationsTest_ReadAndOutput) {
        string path = "test.txt";
        ofstream fs(path);
        fs << "Название: Earth | Дата: 2023.12.21 | Радиус: 6371.0" << endl;
        fs << "Название: Mars | Дата: 2023.12.21 | Радиус: 3389.5" << endl;
        fs.close();

        try {
            ifstream ifs(path);
            vector<Planet> planetVector;
            reader(ifs, planetVector);
            output(planetVector);
        } catch (const exception& e) {
            Assert::Fail(L"Exception caught during file operations.");
        }
    }
};

    TEST_CLASS(PlanetTest) {
public:

    TEST_METHOD(PlanetOutputOperatorTest) {
        Planet planet;
        planet.name = "Earth";
        planet.date.year = 2023;
        planet.date.month = 12;
        planet.date.day = 21;
        planet.radius = 6371.0;

        std::stringstream ss;
        ss << planet;

        std::string expected_output = "Название: Earth | Дата: 2023.12.21 | Радиус: 6371.0";
        Assert::AreEqual(ss.str(), expected_output);
    }

    TEST_METHOD(PlanetInputOperatorTest) {
        Planet planet;
        std::stringstream ss("Название: Mars | Дата: 2023.12.21 | Радиус: 3389.5");
        ss >> planet;

        Assert::AreEqual(planet.name, std::string("Mars"));
        Assert::AreEqual(planet.radius, 3389.5);
        Assert::AreEqual(planet.date.year, 2023);
        Assert::AreEqual(planet.date.month, 12);
        Assert::AreEqual(planet.date.day, 21);
    }
    };

    TEST_CLASS(DateTest) {
public:

    TEST_METHOD(DateOutputOperatorTest) {
        Date date;
        date.year = 2023;
        date.month = 12;
        date.day = 21;
        std::stringstream ss;
        ss << date;

        Assert::AreEqual(ss.str(), std::string("2023.12.21"));
    }

    TEST_METHOD(DateInputOperatorTest) {
        Date date;
        std::stringstream ss("2023.12.21");
        ss >> date;

        Assert::AreEqual(date.year, 2023);
        Assert::AreEqual(date.month, 12);
        Assert::AreEqual(date.day, 21);
    }

    TEST_METHOD(DateLeapYearTest) {
        Date date;
        date.year = 2024;
        date.month = 2;
        date.day = 29;
        std::stringstream ss;
        ss << date;

        Assert::AreEqual(ss.str(), std::string("2024.2.29"));
    }

    TEST_METHOD(DateNonLeapYearTest) {
        Date date;
        std::stringstream ss("2023.2.29");
        ss >> date;

        Assert::AreNotEqual(date.day, 29);
    }
    };
}
