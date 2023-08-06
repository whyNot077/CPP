#include "FragTrap.hpp"

static int max_hit_points = 100;
static int max_energy_points = 100;
static int max_attack_damage = 30;

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << CYAN << "FragTrap constructor called" << DEFAULT << std::endl;
    m_hit_points = max_hit_points;
    m_energy_points = max_energy_points;
    m_attack_damage = max_attack_damage;
    m_max_hit_points = max_hit_points;
}

FragTrap::~FragTrap() {
    std::cout << RED << "FragTrap destructor called" << DEFAULT << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    m_name = other.m_name;
    m_attack_damage = other.m_attack_damage;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    Print::PrintMessage("FragTrap copy constructor called", CYAN);
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    Print::PrintMessage("FragTrap assignment operator called", CYAN);
    if (this != &other) {
        ClapTrap::operator=(other);
        m_name = other.m_name;
    }
    return *this;
}

void FragTrap::attack(std::string const & target) {
    if (!ClapTrap::attack_damage())
        return ;
    std::cout << "FragTrap " << GREEN << m_name << DEFAULT << " attacks " << target << " causing " << BLUE << m_attack_damage << DEFAULT << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << m_name << " has requested a high five!" << std::endl;
}
