#include <iostream>
#include "Array.hpp"

void leaks() {
    std::system("leaks array");
}

int main() {
    Array<int> intArray(5);
    std::atexit(leaks);
    for (unsigned int i = 0; i < intArray.size(); ++i)
        intArray[i] = i;

    try {
        for (unsigned int i = 0; i < intArray.size(); ++i)
            std::cout << intArray[i] << ' ';
        std::cout << std::endl;
        std::cout << intArray[10] << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Array<int> copy;
    copy = intArray;
    Array<Array<int> > arrayArray(2);
    arrayArray[0] = intArray;
    arrayArray[1] = copy;
    try {
        for (unsigned int i = 0; i < arrayArray[0].size(); ++i)
            std::cout << arrayArray[0][i] << " - " << arrayArray[1][i] << std::endl;
            // arrayArray.operator[](0).operator[](i)
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
