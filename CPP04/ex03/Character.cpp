#include "includes.hpp"

Character::Character() : ICharacter() { }

Character::Character(std::string const & name) : ICharacter(name) { }

Character::Character(const Character& other) : ICharacter(other) { }

Character& Character::operator=(const Character& other) {
    if (this != &other)
        ICharacter::operator=(other);
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
}

std::string const& Character::getName() const {
    return m_name;
}

void Character::equip(AMateria* m) {
    ICharacter::equip(m);
}

void Character::unequip(int idx) {
    ICharacter::unequip(idx);
}

void Character::use(int idx, ICharacter& target) {
    ICharacter::use(idx, target);
}