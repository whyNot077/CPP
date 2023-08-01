#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    m_type = copy.getType();
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << CYAN << "Meow meow" << DEFAULT << std::endl;
}