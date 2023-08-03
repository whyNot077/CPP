#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    virtual ~Dog();
    Dog& operator=(const Dog& other);
    virtual void makeSound() const;
};

#endif
