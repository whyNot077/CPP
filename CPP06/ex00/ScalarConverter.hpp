#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <climits>
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
public:
    typedef void (*ConvertAndPrintFunc)(double);

    ScalarConverter() {}
    ~ScalarConverter() {}
    ScalarConverter(const ScalarConverter& copy) { (void)copy; }
    ScalarConverter& operator=(const ScalarConverter& copy) { (void)copy; return *this;}

    static void convert(std::string str);
    static double ConvertDouble(const std::string& str);
    static void ConvertChar(double str);
    static void ConvertInt(double str);
    static void ConvertFloat(double str);
    static void PrintDouble(double d);
};

class NotDouble : public std::exception {
public:
    virtual const char* what() const throw() {
        std::cout << CHAR << IMPOSSIBLE << '\n';
        std::cout << INT << IMPOSSIBLE << '\n';
        std::cout << FLOAT << IMPOSSIBLE << '\n';
        std::cout << DOUBLE << IMPOSSIBLE << '\n';
        exit(1);
        return IMPOSSIBLE;
    }
};

#endif
