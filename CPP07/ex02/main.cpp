#include <iostream>
#include "Array.hpp" // no need to include Array.tpp

int main() {
    Array<int> intArray(5);

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

    return 0;
}
