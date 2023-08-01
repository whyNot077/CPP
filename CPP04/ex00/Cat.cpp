#include "Cat.hpp"

Cat::Cat() : Animal() {
    m_type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    m_type = copy.getType();
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}


Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << CYAN << "Meow meow" << DEFAULT << std::endl;
}

