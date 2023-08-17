#include "includes.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    if (this == &copy) {
        return *this;
    }
    return *this;
}
void ScalarConverter::ConvertChar(double str) {
    char c;

    if (str < CHAR_MIN || str > CHAR_MAX)
        std::cout << CHAR << IMPOSSIBLE << '\n';
    else if (str < 32 || str > 126)
        std::cout << CHAR << NON_DISPLAYABLE << '\n';
    else {
        c = static_cast<char>(str);
        std::cout << CHAR << c << '\n';
    }
}

void ScalarConverter::ConvertInt(double str) {
    int i;

    if (str < INT_MIN || str > INT_MAX)
        std::cout << INT << IMPOSSIBLE << '\n';
    else {
        i = static_cast<int>(str);
        std::cout << INT << i << '\n';
    }
}

void ScalarConverter::ConvertFloat(double str) {
    float f;

    if (str < MIN_FLOAT || str > MAX_FLOAT)
        std::cout << FLOAT << IMPOSSIBLE << '\n';
    else {
        std::cout << std::fixed;
        std::cout.precision(1);
        f = static_cast<float>(str);
        std::cout << FLOAT << f << 'f' << '\n';
    }
}

void is_number(const std::string& str) {
    bool hasDot = false;
    bool hasE = false;
    bool hasF = false;
    int sign = 0;

    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (ch == '.') {
            if (hasDot) throw NotDouble();
            hasDot = true;
        } else if (ch == 'e' || ch == 'E') {
            if (hasE) throw NotDouble();
            hasE = true;
            sign = 0;
        } else if (ch == 'f' || ch == 'F') {
            if (hasF) throw NotDouble();
            hasF = true;
        } else if (ch == '+') {
            if (sign != 0 || (i > 0 && str[i-1] != 'e' && str[i-1] != 'E')) throw NotDouble();
            sign = 1;
        } else if (ch == '-') {
            if (sign != 0 || (i > 0 && str[i-1] != 'e' && str[i-1] != 'E')) throw NotDouble();
            sign = -1;
        } else if (!std::isdigit(ch)) {
            throw NotDouble();
        }
    }
}

double ScalarConverter::ConvertDouble(const std::string& str) {
    is_number(str);
    std::stringstream ss(str);
    double result;
    ss >> result;

    if (ss.fail() || !ss.eof()) {
        throw NotDouble();
    }
    if (result < MIN_DOUBLE || result > MAX_DOUBLE) {
        throw NotDouble();
    }
    return result;
}


void ScalarConverter::PrintDouble(double d) {
    std::cout << std::fixed;
    std::cout.precision(1);
    d = static_cast<double>(d);
    std::cout << DOUBLE << d << '\n';
}

void ScalarConverter::convert(std::string str) {
    if (NanException::IsNanException(str))
        return ;
    double d = ConvertDouble(str);
    ConvertAndPrintFunc funcs[] = {ConvertChar, ConvertInt, ConvertFloat, PrintDouble};
    size_t funcsSize = sizeof(funcs) / sizeof(ConvertAndPrintFunc);

    for (size_t i = 0; i < funcsSize; ++i) {
        funcs[i](d);
    }
}
