#include "Animal.hpp"

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignation operator called" << std::endl;
    m_type = other.getType();
    return *this;
}

std::string Animal::getType() const {
    return m_type;
}
