#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T const & element) {
    std::cout << element << " ";
}

template <typename T, size_t N>
void print_array(T (&array)[N]) {
    std::cout << "Array: ";
    iter(array, N, printElement<T>);
    std::cout << std::endl;
}


int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    print_array(arrInt);

    char arrChar[] = {'a', 'b', 'c', 'd', 'e'};
    print_array(arrChar);

    std::string arrString[] = {"Hello", "World", "!"};
    print_array(arrString);

    float arrFloat[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    print_array(arrFloat);

    return 0;
}