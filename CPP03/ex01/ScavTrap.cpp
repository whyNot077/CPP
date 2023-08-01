#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    m_hit_points = 100;
    m_energy_points = 50;
    m_attack_damage = 20;
    Print::PrintMessage("ScavTrap constructor called", GREEN);
}

ScavTrap::~ScavTrap() {
    Print::PrintMessage("ScavTrap " + m_name + " destructor called", RED);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    m_name = other.m_name;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    m_attack_damage = other.m_attack_damage;
    Print::PrintMessage("ScavTrap copy constructor called", GREEN);
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    Print::PrintMessage("ScavTrap assignment operator called", GREEN);
    if (this != &other) {
        ClapTrap::operator=(other);
        m_name = other.m_name;
    }
    return *this;
}

void ScavTrap::attack(std::string const & target) {
    m_energy_points -= 1;
    std::cout << YELLOW << "ScavTrap " << DEFAULT << m_name << " attacks " << target << " causing " << BLUE << m_attack_damage << DEFAULT << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    m_energy_points -= 1;
    std::cout << YELLOW << "ScavTrap " << DEFAULT << m_name << " has been repaired by " << BLUE << amount << DEFAULT << " points!" << std::endl;
}

void ScavTrap::guardGate() {
    Print::PrintMessage("ScavTrap " + m_name + " has entered in Gate keeper mode", YELLOW);
}
