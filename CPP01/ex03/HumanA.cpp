#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) \
: m_name(name), m_weapon(weapon) {
    std::cout << BLACK << name << \
        NEW_HUMAN << DEFAULT << std::endl;
}

void HumanA::attack() const {
    std::cout << GREEN << m_name << ATTACK << \
        m_weapon.getType() << DEFAULT << std::endl;
}
