#include "pch.h"
#include "CppUnitTest.h"
#include <exception>
#include <string>
#include <stdexcept>
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
            planet.name = "Mercury";
            planet.date.year = 1631;
            planet.date.month = 11;
            planet.date.day = 7;
            planet.radius = 2439.7;

            std::stringstream ss;
            ss << planet;

            std::string expected_output = "Название: Mercury | Дата: 1631.11.7 | Радиус: 2439.7";
            Assert::AreEqual(ss.str(), expected_output);
        }
   


        TEST_METHOD(PlanetInputOperatorTest) {
            Planet planet;
            std::stringstream ss(" <Mars> 2023.12.21 3389.5");
            ss >> planet;

            Assert::AreEqual(planet.name, std::string("Mars"));

            Assert::AreEqual(planet.date.year, 2023);
            Assert::AreEqual(planet.date.month, 12);
            Assert::AreEqual(planet.date.day, 21);  
            Assert::AreEqual(planet.radius, 3389.5);
        }


        TEST_METHOD(InvalidPlanetRadius)
        {
            Assert::ExpectException<std::invalid_argument>([&]() { Planet planet("Earth", Date(1, 1, 2023), -10.0); });
        }

        TEST_METHOD(InvalidPlanetName1)
        {
            Assert::ExpectException<std::invalid_argument>([&]() { Planet planet("Mars123", Date(1, 1, 2023), 20.0); });
        }

        TEST_METHOD(InvalidPlanetName2)
        {
            Assert::ExpectException<std::invalid_argument>([&]() { Planet planet("Jupiter!", Date(1, 1, 2023), 50.0); });
        }

        TEST_METHOD(ValidPlanetName)
        {
            Planet planet;
            planet.name = "Earth";
            Assert::AreEqual("Earth", planet.name.c_str());
        }

        TEST_METHOD(InvalidPlanetName)
        {
            Planet planet;
            planet.name = "";
            Assert::AreNotEqual("Earth", planet.name.c_str());
        }

        TEST_METHOD(ValidPlanetRadius)
        {
            Planet planet;
            planet.radius = 6371.0; 
            Assert::AreEqual(6371.0, planet.radius);
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
        TEST_METHOD(InvalidDateInputTest)
        {
            Date date;
            std::istringstream ss("50.20.2023");
            ss >> date;

            Assert::IsFalse(ss.fail());
        }

        TEST_METHOD(ValidDateInputTest)
        {
            Date date;
            std::istringstream ss("2023.12.21");
            ss >> date;

            Assert::IsFalse(ss.fail());
            Assert::AreEqual(2023, date.year);
            Assert::AreEqual(12, date.month);
            Assert::AreEqual(21, date.day);
        }

        

        TEST_METHOD(InvalidDate1)
        {
            Assert::ExpectException<std::invalid_argument>([&]() { Date date(-1, -1, -1); });
        }

        TEST_METHOD(InvalidDate2)
        {
            Assert::ExpectException<std::invalid_argument>([&]() { Date date(31, 11, 2023); });
        }

        TEST_METHOD(InvalidDate3)
        {
            Assert::ExpectException<std::invalid_argument>([&]() { Date date(0, 0, 0); });
        }

        TEST_METHOD(InvalidDate4)
        {
            Assert::ExpectException<std::invalid_argument>([&]() { Date date(-1, -1, -1); });
        }



    };
}
