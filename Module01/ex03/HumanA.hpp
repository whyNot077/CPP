#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    std::string m_name;
    Weapon& m_weapon;

public:
    // Constructor with name and weapon as parameters and store them in m_name and m_weapon
    HumanA(const std::string& name, Weapon& weapon);

    // Perform attack with the associated weapon
    void attack() const;
};

#endif
