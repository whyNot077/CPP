#include "Dog.hpp"

Dog::Dog() : Animal(){
    m_type = "Dog";
    m_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    m_type = other.getType();
    m_brain = new Brain(*other.m_brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete m_brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete m_brain;
        m_brain = new Brain(*other.m_brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << BLUE << "Woof Woof!" << DEFAULT << std::endl;
}
