#include "Fixed.hpp"

Fixed::Fixed() : m_value(0) { }

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed::Fixed(const int value) {
    m_value = value << m_fractional_bits;
}

Fixed::Fixed(const float value) {
    m_value = roundf(value * (1 << m_fractional_bits));
}

int Fixed::getRawBits(void) const {
    return m_value;
}

void Fixed::setRawBits(int const raw) {
    m_value = raw;
}

Fixed::~Fixed() { }

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
    if (this != &fixed) {
        m_value = fixed.getRawBits();
    }
    return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
    return m_value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
    return m_value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return m_value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return m_value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
    return m_value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return m_value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(toFloat() / fixed.toFloat());
}


Fixed& Fixed::operator++() {
    ++m_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--() {
    --m_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}
