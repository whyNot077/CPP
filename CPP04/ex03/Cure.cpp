#include "includes.hpp"

Cure::Cure() : AMateria("cure") { }

Cure::Cure(const Cure& other) : AMateria(other) { }

Cure& Cure::operator=(const Cure& other) {
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << DEFAULT << std::endl;
}
