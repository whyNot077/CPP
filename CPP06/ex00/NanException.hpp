#ifndef NANEXCEPTION_HPP
# define NANEXCEPTION_HPP

#include <string>
#include <iostream>

#define NON_DISPLAYABLE "Non displayable"
#define IMPOSSIBLE "impossible"
#define CHAR "char: "
#define INT "int: "
#define FLOAT "float: "
#define DOUBLE "double: "
#define STAR "*"
#define NAN_STR "nan"
#define INF "inf"
#define MINUS_INF "-inf"
#define NANF "nanf"
#define INFF "inff"
#define MINUS_INFF "-inff"


class NanException {
struct NanValue {
    std::string name;
    void (*printFunction)();
};

private:
    NanException(){}
    ~NanException(){}
    NanException(const NanException& copy){ (void)copy; }
    NanException& operator=(const NanException& copy);

public:
    static NanValue nan_value[];
    static bool IsNanException(std::string str);
    static void PrintNan();
    static void PrintInf();
    static void PrintMinusInf();
    static void PrintNanFloat();
    static void PrintInfFloat();
    static void PrintMinusInfFloat();
};

#endif