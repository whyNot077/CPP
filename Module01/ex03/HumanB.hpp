#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    std::string m_name;
    Weapon* m_weapon;

public:
    // Constructor with name as parameter and store it in m_name
    HumanB(const std::string& name);

    // Constructor with name and weapon as parameters and store them in m_name and m_weapon
    HumanB(const std::string& name, Weapon& weapon);

    // Perform attack with the associated weapon
    void attack() const;

    // Set the weapon
    void setWeapon(Weapon& weapon);
};

#endif
