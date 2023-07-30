# include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << CYAN << a << DEFAULT << std::endl;
    std::cout << "b is " << CYAN << b << DEFAULT << std::endl;
    std::cout << "c is " << CYAN << c << DEFAULT << std::endl;
    std::cout << "d is " << CYAN << d << DEFAULT << std::endl;

    std::cout << "I stored a to Fixed point value of " << MAGENTA << a.getRawBits() << DEFAULT << std::endl;
    std::cout << "I stored b to Fixed point value of " << MAGENTA << b.getRawBits() << DEFAULT << std::endl;
    std::cout << "I stored c to Fixed point value of " << MAGENTA << c.getRawBits() << DEFAULT << std::endl;
    std::cout << "I stored d to Fixed point value of " << MAGENTA << d.getRawBits() << DEFAULT << std::endl;

    std::cout << "a is " << BLUE << a.toInt() << DEFAULT << " as integer" << std::endl;
    std::cout << "b is " << BLUE << b.toInt() << DEFAULT << " as integer" << std::endl;
    std::cout << "c is " << BLUE << c.toInt() << DEFAULT << " as integer" << std::endl;
    std::cout << "d is " << BLUE << d.toInt() << DEFAULT << " as integer" << std::endl;

    return 0;
}
