#include "Fixed.hpp"

Fixed::Fixed() : m_value(0) {
    std::cout << GREEN << DEFAULT_CONSTRUCTOR_LOG << DEFAULT << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << GREEN << COPY_CONSTRUCTOR_LOG << DEFAULT << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value) {
    std::cout << GREEN << INT_CONSTRUCTOR_LOG << DEFAULT << std::endl;
    m_value = value << m_fractional_bits;
}

Fixed::Fixed(const float value) {
    std::cout << GREEN << FLOAT_CONSTRUCTOR_LOG << DEFAULT << std::endl;
    m_value = roundf(value * (1 << m_fractional_bits));
}

int Fixed::getRawBits(void) const {
    return m_value;
}

void Fixed::setRawBits(int const raw) {
    m_value = raw;
    std::cout << BLUE << SET_RAW_BITS_LOG << DEFAULT << std::endl;
}

Fixed::~Fixed() {
    std::cout << RED << DESTRUCTOR_LOG << DEFAULT << std::endl;
}

float Fixed::toFloat(void) const {
    return (float)m_value / (1 << m_fractional_bits);
}

int Fixed::toInt(void) const {
    return m_value >> m_fractional_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << BLUE << COPY_ASSIGNMENT_LOG << DEFAULT << std::endl;
    if (this != &fixed) {
        m_value = fixed.getRawBits();
    }
    return *this;
}
