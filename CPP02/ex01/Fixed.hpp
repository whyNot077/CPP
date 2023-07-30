
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

#define DEFAULT_CONSTRUCTOR_LOG "Default constructor called"
#define INT_CONSTRUCTOR_LOG "Int constructor called"
#define FLOAT_CONSTRUCTOR_LOG "Float constructor called"
#define COPY_CONSTRUCTOR_LOG "Copy constructor called"
#define COPY_ASSIGNMENT_LOG "Copy assignment operator called"
#define GET_RAW_BITS_LOG "getRawBits member function called"
#define SET_RAW_BITS_LOG "setRawBits member function called"
#define DESTRUCTOR_LOG "Destructor called"

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
