#include "includes.hpp"

Character::Character() : ICharacter(), Ground(){ }

Character::Character(std::string const & name) : ICharacter(name), Ground(){ }

Character::Character(const Character& other) : ICharacter(other), Ground(other) {
    m_name = other.m_name;
    copy_slots(other.m_slot, m_slot);
}

void copy_slots(AMateria* const source[4], AMateria* destination[4]) {
    for (int i = 0; i < 4; i++) {
        if (source[i] != nullptr)
            destination[i] = source[i]->clone();
        else
            destination[i] = nullptr;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        m_name = other.m_name;
        copy_slots(other.m_slot, m_slot);
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (m_slot[i] != NULL)
            delete m_slot[i];
    }
}

std::string const& Character::getName() const {
    return m_name;
}

void Character::equip(AMateria* m) {
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++) {
        if (m_slot[i] == NULL) {
            m_slot[i] = m;
            return;
        }
    }
    std::cout << RED << "You can't equip more than 4 materia " << DEFAULT << std::endl;
    addMateria(m);
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4)
        return;
    std::cout << "You unequip " << BLUE << m_slot[idx]->getType() << DEFAULT << std::endl;
    addMateria(m_slot[idx]);
    m_slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || m_slot[idx] == NULL)
        return;
    m_slot[idx]->use(target);
}
