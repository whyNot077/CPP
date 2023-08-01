#include "DiamondTrap.hpp"
#include <string>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
    Print::PrintMessage("DiamondTrap " + m_name + " constructor called", MAGENTA);
    m_name = name;
    m_hit_points = FragTrap::m_hit_points;
    m_energy_points = ScavTrap::m_energy_points;
    m_attack_damage = FragTrap::m_attack_damage;
}

DiamondTrap::~DiamondTrap() {
    Print::PrintMessage("DiamondTrap " + m_name + " destructor called", RED);
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    Print::PrintMessage("DiamondTrap copy constructor called", CYAN);
    m_name = other.m_name;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    m_attack_damage = other.m_attack_damage;
}


DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    Print::PrintMessage("DiamondTrap assignation operator called", CYAN);
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        m_name = other.m_name;
    }
    return *this;
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (m_energy_points == 0) {
        std::cout << "DiamondTrap " << m_name << " has no energy points left!" << std::endl;
        return;
    }
    if (m_hit_points == 0) {
        std::cout << "DiamondTrap " << m_name << " has no hit points left!" << std::endl;
        return;
    }
    m_hit_points += amount;
    if (m_hit_points > 100)
        m_hit_points = 100;
    m_energy_points--;
    std::cout << YELLOW << "DiamondTrap " << DEFAULT << m_name << " has been repaired by " << BLUE << amount << DEFAULT << " points!" << std::endl;
}

void DiamondTrap::attack(std::string const & target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << GREEN << m_name << DEFAULT <<\
         " and my ClapTrap name is " << BLUE << ClapTrap::m_name << DEFAULT << std::endl;
}