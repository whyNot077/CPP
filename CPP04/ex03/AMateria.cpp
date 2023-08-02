#include "includes.hpp"

AMateria::AMateria() : m_type("default") { }

AMateria::AMateria(std::string const & type) : m_type(type) { }

AMateria::AMateria(const AMateria& other) : m_type(other.m_type) { }

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
        m_type = other.m_type;
    return *this;
}

AMateria::~AMateria() {
    std::cout << RED << "AMateria destructor called" << DEFAULT << std::endl;
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