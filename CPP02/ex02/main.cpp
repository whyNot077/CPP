#include "Fixed.hpp"

void print_this(const Fixed &fixed) {
    std::cout << "This is " << CYAN << fixed << DEFAULT << std::endl;
    std::cout << "I stored a to Fixed point value of " << MAGENTA << fixed.getRawBits() << DEFAULT << "\n" << std::endl;
}

void print_max(const Fixed &a, const Fixed &b) {
    std::cout << "a is " << CYAN << a << DEFAULT << std::endl;
    std::cout << "b is " << CYAN << b << DEFAULT << std::endl;
    std::cout << "max is " << CYAN << Fixed::max(a, b) << DEFAULT << "\n" << std::endl;
}

int main() {
    Fixed a(10);
    Fixed const b(Fixed(100));

    std::cout << a << std::endl;
    print_this(a);

    std::cout << ++a << std::endl;
    print_this(a);

    std::cout << a << std::endl;
    print_this(a);

    std::cout << a++ << std::endl;
    print_this(a);

    std::cout << a << std::endl;
    print_this(a);

    std::cout << b << std::endl;
    print_this(b);

    std::cout << a + b << std::endl;
    print_this(a + b);

    std::cout << a - b << std::endl;
    print_this(a - b);

    std::cout << a * b << std::endl;
    print_this(a * b);

    std::cout << a / b << std::endl;
    print_this(a / b);

    std::cout << Fixed::max(a, b) << std::endl;
    print_max(a, b);

    return 0;
}
