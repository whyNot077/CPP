#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignation operator called" << std::endl;
    m_type = other.getType();
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal makeSound called" << std::endl;
}

std::string Animal::getType() const {
    return m_type;
}
