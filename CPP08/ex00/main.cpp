#include <iostream>
#include "easyfind.hpp"
#include <iterator>

int main() {
    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 50; i > 0; i -= 10)
        vec.push_back(i);

    for (int i = 0; i < 5; i++)
        lst.push_back(i * 10);

    try {
        std::vector<int>::const_iterator vecIt = easyfind(vec, 10);
        std::cout << "Find the index of 10 in vec: " << std::distance(vec.cbegin(), vecIt) << std::endl;
        
        std::list<int>::const_iterator lstIt = easyfind(lst, 10);
        std::cout << "Find the index of 10 in lst: " << std::distance(lst.cbegin(), lstIt) << std::endl;
        
        vecIt = easyfind(vec, 50);
        std::cout << "Find the index of 50 in vec: " << std::distance(vec.cbegin(), vecIt) << std::endl;
        
        lstIt = easyfind(lst, 50);
        std::cout << "Find the index of 50 in lst: " << std::distance(lst.cbegin(), lstIt) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
