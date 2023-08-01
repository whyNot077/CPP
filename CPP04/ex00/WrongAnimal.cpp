#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
    m_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    m_type = copy.getType();
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    m_type = other.getType();
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return m_type;
}