# include "Print.hpp"

void Print::PrintMessage(const std::string& message, const std::string &color) {
    std::cout << color << message << DEFAULT << std::endl;
}

void Print::PrintWithoutNewline(const std::string& message, const std::string &color) {
    std::cout << color << message << DEFAULT;
}
