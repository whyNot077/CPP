#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[0m"

class Print {
public:
    // print message with color
    static void PrintMessage(const std::string& message, const std::string &color);

    // print message without endl
    static void PrintWithoutNewline(const std::string& message, const std::string &color);
};

#endif
