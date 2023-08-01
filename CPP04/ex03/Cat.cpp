#include "Cat.hpp"

Cat::Cat() : Animal() {
    m_type = "Cat";
    m_brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    m_type = copy.getType();
    m_brain = new Brain(*copy.m_brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete m_brain;
        m_brain = new Brain(*other.m_brain);
    }
    return *this;
}


Cat::~Cat() {
    delete m_brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << CYAN << "Meow meow" << DEFAULT << std::endl;
}

