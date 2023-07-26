#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : m_name(name), m_weapon(NULL) {
    std::cout << BLACK << name << \
        NEW_HUMAN << DEFAULT << std::endl;
}

HumanB::HumanB(const std::string& name, Weapon& weapon) : m_name(name), m_weapon(&weapon) {
    std::cout << BLACK << name << \
        NEW_HUMAN << DEFAULT << std::endl;
}

void HumanB::attack() const {
    if(m_weapon)
        std::cout << BLUE << m_name << \
            ATTACK << m_weapon->getType() << DEFAULT << std::endl;
    else
        std::cout << RED << m_name << NO_WEAPON << DEFAULT << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    if (m_weapon) {
        std::cout << BLACK << m_name << \
            CHANGED_WEAPON << m_weapon->getType() << " -> " << weapon.getType() << DEFAULT << std::endl;
    }
    m_weapon = &weapon;
    std::cout << YELLOW << m_name << \
        SET_WEAPON << m_weapon->getType() << DEFAULT << std::endl;
}
