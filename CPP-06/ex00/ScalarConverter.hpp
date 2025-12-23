#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isPseudoLiteral(const std::string& str);

    static void printChar(double value, bool impossible);
    static void printInt(double value, bool impossible);
    static void printFloat(double value);
    static void printDouble(double value);

public:
    static void convert(const std::string& literal);
};

#endif