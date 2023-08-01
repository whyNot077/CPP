#include "Dog.hpp"

Dog::Dog() : Animal(){
    m_type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    m_type = other.getType();
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << BLUE << "Woof Woof!" << DEFAULT << std::endl;
}
