#include "Span.hpp"
#include <iostream>

int main() {
    Span sp = Span(50000);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "--- Span 1 ---" << std::endl;
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
    std::cout << "====================" << std::endl;
    try {
        sp.addNumber(100, 10000);
        std::cout << "--- Span 2 ---" << std::endl;
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
        std::cout << "====================" << std::endl;

        sp.addNumber(sp.begin(), sp.end());
        std::cout << "--- Span 3 ---" << std::endl;
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
        std::cout << "====================" << std::endl;

        sp.addNumber(-1000, 25000);
        std::cout << "--- Span 4 ---" << std::endl;
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
        std::cout << "====================" << std::endl;

        sp.addNumber(sp.begin(), sp.end());
        std::cout << "--- Span 5 ---" << std::endl;
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
        std::cout << "====================" << std::endl;

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}