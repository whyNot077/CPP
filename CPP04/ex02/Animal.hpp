#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
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

class Animal{
protected:
    std::string m_type;
    Animal() {}
    Animal(const Animal& other) { *this = other; }

public:
    virtual ~Animal();
    Animal& operator=(const Animal& other);
    virtual void makeSound() const;
    std::string getType() const;
    virtual void think() const;
};

#endif
