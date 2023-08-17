#include "includes.hpp"

const char* NotDouble::what() const throw() {
    std::cout << CHAR << IMPOSSIBLE << '\n';
    std::cout << INT << IMPOSSIBLE << '\n';
    std::cout << FLOAT << IMPOSSIBLE << '\n';
    std::cout << DOUBLE << IMPOSSIBLE << '\n';
    exit(1);
    return IMPOSSIBLE;
}