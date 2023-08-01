#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    ~Dog();
    Dog& operator=(const Dog& other);
    void makeSound() const;
};

#endif
