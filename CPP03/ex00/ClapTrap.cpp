#include "ClapTrap.hpp"

#define CLAPTRAP "ClapTrap "
#define CREATED " is created."
#define DESTROYED " is destroyed."
#define COPIED " is copied."
#define ATTACK " attacks "
#define CAUSING " causing "
#define POINTS " points of damage!"
#define TAKES " takes "
#define REPAIRED " is repaired "

static int max_hit_points = 10;
static int max_energy_points = 10;
static int max_attack_damage = 0;

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hit_points(max_hit_points), \
m_energy_points(max_energy_points), m_attack_damage(max_attack_damage), \
m_max_hit_points(max_hit_points) {
    std::cout << CLAPTRAP << BLUE << m_name << DEFAULT << CREATED << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : m_name(other.m_name), m_hit_points(other.m_hit_points), m_energy_points(other.m_energy_points), \
      m_attack_damage(other.m_attack_damage), m_max_hit_points(other.m_max_hit_points) {
    std::cout << CLAPTRAP << BLUE << m_name << DEFAULT << COPIED << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this == &other)
        return *this;
    std::string tmp = m_name;
    m_name = other.m_name;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    m_attack_damage = other.m_attack_damage;
    m_max_hit_points = other.m_max_hit_points;
    std::cout << CLAPTRAP << BLUE << tmp << DEFAULT << \
        " is now " << CYAN << m_name << DEFAULT << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << CLAPTRAP << m_name << DESTROYED << std::endl;
}

bool ClapTrap::check_invalid_action() {
    if (m_energy_points > 0 && m_hit_points > 0)
        return false;
    std::cout << CLAPTRAP << m_name << RED << " You can't do anything !" << DEFAULT << std::endl;
    return true;
}

bool ClapTrap::attack_damage(void) {
    if (check_invalid_action())
        return false;
    m_energy_points--;
    if (m_energy_points < 0)
        m_energy_points = 0;
    return true;
}

void ClapTrap::attack(std::string const & target) {
    if (!attack_damage())
        return ;
    std::cout << CLAPTRAP << BLUE << m_name << DEFAULT << ATTACK << \
        CYAN << target << DEFAULT << CAUSING \
        << RED << m_attack_damage << DEFAULT << POINTS << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    m_hit_points -= amount;
    if (m_hit_points < 0)
    {
        m_hit_points = 0;
    }
    std::cout << CLAPTRAP << BLUE << m_name << DEFAULT << TAKES << \
        RED << amount << DEFAULT << POINTS << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount) {
    if (check_invalid_action())
        return ;
    m_hit_points += amount;
    if (m_hit_points > m_max_hit_points)
        m_hit_points = m_max_hit_points;
    m_energy_points--;
    std::cout << BLUE << m_name << DEFAULT << REPAIRED \
        << GREEN << amount << DEFAULT << POINTS << std::endl;
}

void ClapTrap::PrintStats() {
    std::cout << " ----- Stats for " << m_name << " -----" << std::endl;
    std::cout << "Hit Points: " << m_hit_points << std::endl;
    std::cout << "Energy Points: " << m_energy_points << std::endl;
    std::cout << "Attack Damage: " << m_attack_damage << std::endl;
    std::cout << " --------------------------" << std::endl;
}
