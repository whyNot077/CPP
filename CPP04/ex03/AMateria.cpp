#include "includes.hpp"

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
        m_type = other.m_type;
    return *this;
}

std::string const & AMateria::getType() const {
    return m_type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "AMateria use function called" << std::endl;
}

AMateria* AMateria::clone() const {
    return new AMateria(*this);
}