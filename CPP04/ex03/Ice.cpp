#include "includes.hpp"

Ice::Ice() : AMateria("ice") { }

Ice::Ice(const Ice& other) : AMateria(other) { }

Ice& Ice::operator=(const Ice& other) {
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << GREEN << "* shoots an ice bolt at " << target.getName() << " *" << DEFAULT << std::endl;
}
