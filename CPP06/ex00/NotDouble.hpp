#ifndef NOT_DOUBLE_HPP
# define NOT_DOUBLE_HPP

#include <string>
#include <iostream>
#include <exception>

class NotDouble : public std::exception {
public:
    virtual const char* what() const throw();
};

#endif