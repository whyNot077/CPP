#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include "color.hpp"

#define NON_DISPLAYABLE "Non displayable"
#define IMPOSSIBLE "impossible"
#define CHAR "char: "
#define INT "int: "
#define FLOAT "float: "
#define DOUBLE "double: "
#define STAR "*"
#define MIN_FLOAT -3.402823e+38
#define MAX_FLOAT 3.402823e+38
#define MIN_DOUBLE -1.797693e+308
#define MAX_DOUBLE 1.797693e+308

class ScalarConverter {
private:
    ScalarConverter() {}
    ScalarConverter(const ScalarConverter& copy);
    ~ScalarConverter() {}
    ScalarConverter& operator=(const ScalarConverter& copy);

public:
    typedef void (*ConvertAndPrintFunc)(double);
    static void convert(std::string str);
    static double ConvertDouble(const std::string& str);
    static void ConvertChar(double str);
    static void ConvertInt(double str);
    static void ConvertFloat(double str);
    static void PrintDouble(double d);
};

#endif
