#include "NanException.hpp"

NanException::NanValue NanException::nan_value[] = {
    {NAN_STR, &NanException::PrintNan},
    {INF, &NanException::PrintInf},
    {MINUS_INF, &NanException::PrintMinusInf},
    {NANF, &NanException::PrintNan},
    {INFF, &NanException::PrintInf},
    {MINUS_INFF, &NanException::PrintMinusInf},
};

NanException::NanException(const NanException& copy) {
    (void)copy;
}

NanException& NanException::operator=(const NanException& copy) {
    if (this == &copy) {
        return *this;
    }
    return *this;
}

bool NanException::IsNanException(std::string str) {
    for (size_t i = 0; i < sizeof(nan_value) / sizeof(NanValue); i++) {
        if (str == nan_value[i].name) {
            nan_value[i].printFunction();
            return true;
        }
    }
    return false;
}

void NanException::PrintNan() {
    std::cout << CHAR << IMPOSSIBLE << "\n";
    std::cout << INT << IMPOSSIBLE << "\n";
    std::cout << FLOAT << NANF << "\n";
    std::cout << DOUBLE << NAN << "\n";
}

void NanException::PrintInf() {
    std::cout << CHAR << IMPOSSIBLE << "\n";
    std::cout << INT << IMPOSSIBLE << "\n";
    std::cout << FLOAT << INFF << "\n";
    std::cout << DOUBLE << INF << "\n";
}

void NanException::PrintMinusInf() {
    std::cout << CHAR << IMPOSSIBLE << "\n";
    std::cout << INT << IMPOSSIBLE << "\n";
    std::cout << FLOAT << MINUS_INFF << "\n";
    std::cout << DOUBLE << MINUS_INF << "\n";
}
