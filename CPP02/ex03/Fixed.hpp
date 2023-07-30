
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[0m"

class Fixed {
private:
    int m_value;
    static const int m_fractional_bits = 8;

public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed(const int value);
    Fixed(const float value);

    Fixed &operator=(const Fixed &fixed);
    bool operator<(const Fixed &fixed) const;
    bool operator>(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;

    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;

    Fixed& operator++();         // prefix ++. 서로 다른 매개변수 가져야 함
    Fixed operator++(int dummy); // postfix ++
    Fixed& operator--();         // prefix --
    Fixed operator--(int dummy); // postfix --

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    
    ~Fixed();

    int getRawBits(void) const;

    void setRawBits(int const raw);

    // converts fixed point value to floating point value
    float toFloat(void) const;

    // converts fixed point value to integer value
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
