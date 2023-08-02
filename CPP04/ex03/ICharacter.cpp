#include "includes.hpp" 

ICharacter::ICharacter() : m_name("default") { }

ICharacter::ICharacter(std::string const & name) : m_name(name) { }

ICharacter::ICharacter(const ICharacter& other) : m_name(other.m_name) { }

ICharacter& ICharacter::operator=(const ICharacter& other) {
    if (this != &other) {
        delete_materials(m_slot);
        m_name = other.m_name;
    }
    return *this;
}

ICharacter::~ICharacter() {
    std::cout << "ICharacter destructor called" << std::endl;
    delete_materials(m_slot);
}

std::string const & ICharacter::getName() const {
    return m_name;
}

void ICharacter::equip(AMateria* m) {
    if (m == nullptr)
        return;
    for (int i = 0; i < 4; i++) {
        if (m_slot[i] == nullptr) {
            std::cout << "Equipped " << BLUE << m->getType() << DEFAULT << " materia" << std::endl;
            m_slot[i] = m;
            return;
        }
    }
    std::cout << "No more space in the inventory" << std::endl;
    delete m;
}

void ICharacter::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return;
    m_slot[idx] = nullptr;
}

void ICharacter::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3 || m_slot[idx] == nullptr)
        return;
    m_slot[idx]->use(target);
}
