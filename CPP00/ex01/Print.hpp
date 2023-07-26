#ifndef PRINT_HPP
#define PRINT_HPP

#include "define.hpp"
#include <iostream>

class Print {
public:
    // print message with color
    static void PrintMessage(const std::string& message, const std::string &color);

    // print message without endl
    static void PrintWithoutNewline(const std::string& message, const std::string &color);
};

#endif
