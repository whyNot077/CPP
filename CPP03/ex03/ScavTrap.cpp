#include "ScavTrap.hpp"

static int max_hit_points = 100;
static int max_energy_points = 50;
static int max_attack_damage = 20;

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    m_scav_name = name;
    m_hit_points = max_hit_points;
    m_energy_points = max_energy_points;
    m_attack_damage = max_attack_damage;
    m_max_hit_points = max_hit_points;
    Print::PrintMessage("ScavTrap constructor called", GREEN);
}

ScavTrap::~ScavTrap() {
    Print::PrintMessage("ScavTrap " + m_scav_name + " destructor called", RED);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    m_scav_name = other.m_scav_name;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    m_attack_damage = other.m_attack_damage;
    m_max_hit_points = other.m_max_hit_points;
    Print::PrintMessage("ScavTrap copy constructor called", GREEN);
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    Print::PrintMessage("ScavTrap assignment operator called", GREEN);
    if (this != &other) {
        ClapTrap::operator=(other);
        m_scav_name = other.m_scav_name;
    }
    return *this;
}

void ScavTrap::attack(std::string const & target) {
    if (!ClapTrap::attack_damage())
        return ;
    std::cout << "ScavTrap " << BLUE << m_scav_name << DEFAULT << " attacks " << target << " causing " << BLUE << m_attack_damage << DEFAULT << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    Print::PrintMessage("ScavTrap " + m_scav_name + " has entered in Gate keeper mode", YELLOW);
}
