#include "DiamondTrap.hpp"
#include <string>

static int max_hit_points = 100;
static int max_energy_points = 50;
static int max_attack_damage = 30;

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    m_diamond_name = name;
    m_hit_points = max_hit_points;
    m_energy_points = max_energy_points;
    m_attack_damage = max_attack_damage;
    m_max_hit_points = max_hit_points;
    Print::PrintMessage("DiamondTrap " + m_diamond_name + " constructor called", MAGENTA);
}

DiamondTrap::~DiamondTrap() {
    Print::PrintMessage("DiamondTrap " + m_diamond_name + " destructor called", RED);
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    Print::PrintMessage("DiamondTrap copy constructor called", CYAN);
    m_diamond_name = other.m_diamond_name;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    m_attack_damage = other.m_attack_damage;
    m_max_hit_points = other.m_max_hit_points;
}


DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    Print::PrintMessage("DiamondTrap assignation operator called", CYAN);
    if (this != &other) {
        ClapTrap::operator=(other);
        m_diamond_name = other.m_diamond_name;
    }
    return *this;
}

void DiamondTrap::attack(std::string const & target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << GREEN << m_diamond_name << DEFAULT <<\
         " and my ClapTrap name is " << BLUE << m_name << DEFAULT << std::endl;
}