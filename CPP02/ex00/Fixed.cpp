#include "Fixed.hpp"

Fixed::Fixed() : m_value(0) {
    std::cout << GREEN << DEFAULT_CONSTRUCTOR_LOG << DEFAULT << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << GREEN << COPY_CONSTRUCTOR_LOG << DEFAULT << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << BLUE << COPY_ASSIGNMENT_LOG << DEFAULT << std::endl;
    if (this != &fixed) {
        m_value = fixed.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << BLACK << GET_RAW_BITS_LOG << DEFAULT << std::endl;
    return m_value;
}

void Fixed::setRawBits(int const raw) {
    m_value = raw;
    std::cout << BLUE << SET_RAW_BITS_LOG << DEFAULT << std::endl;
}

Fixed::~Fixed() {
    std::cout << RED << DESTRUCTOR_LOG << DEFAULT << std::endl;
}