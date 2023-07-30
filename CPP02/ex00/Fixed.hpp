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
#define COPY_CONSTRUCTOR_LOG "Copy constructor called"
#define COPY_ASSIGNMENT_LOG "Copy assignment operator called"
#define GET_RAW_BITS_LOG "getRawBits member function called"
#define SET_RAW_BITS_LOG "setRawBits member function called"
#define DESTRUCTOR_LOG "Destructor called"

const int FRACTIONAL_BITS = 8;

class Fixed {
private:
    int m_value;
    static const int m_fractional_bits = FRACTIONAL_BITS;

public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};


#endif
