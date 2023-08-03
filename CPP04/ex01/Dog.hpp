#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#define DOG_IDEA "I am the most genious dog!,I am happy,Look at me!,멍멍멍 \\ ( ^ㅅ^) /,\
난 천재야!,나눈야 해퓌~~,귀여운 날 봐!,멍멍멍 \\ ( ^ㅅ^) /,\
I will conquer the world,I am the best,멍멍멍 \\ ( ^ㅅ^) /"

class Dog : public Animal {
private:
    Brain* m_brain;

public:
    Dog();
    Dog(const Dog& other);
    virtual ~Dog();
    Dog& operator=(const Dog& other);
    virtual void makeSound() const;
    virtual void think() const;
};

std::string* split(const std::string& str, char delim, int& count);

#endif
