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


ClapTrap::ClapTrap(std::string name) : m_name(name), m_hit_points(10), m_energy_points(10), m_attack_damage(0) {
    std::cout << CLAPTRAP << m_name << CREATED << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    if (this == &other)
        return;
    *this = other;
    std::cout << CLAPTRAP << BLUE << m_name << DEFAULT << COPIED << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this == &other)
        return *this;
    if (!m_name.empty())
        std::cout << CLAPTRAP << BLUE << m_name << DEFAULT << " is now " << YELLOW << other.m_name << DEFAULT << std::endl;
    m_name = other.m_name;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    m_attack_damage = other.m_attack_damage;
    return *this;
}

ClapTrap::~ClapTrap() {
    Print::PrintMessage(CLAPTRAP + m_name + DESTROYED, DEFAULT);
}

void ClapTrap::attack(std::string const & target) {
    if (m_energy_points == 0) {
        Print::PrintMessage(CLAPTRAP + m_name + " has no energy left to attack!", DEFAULT);
        return;
    }
    m_energy_points--;
    Print::PrintMessage(CLAPTRAP + m_name + ATTACK + target + CAUSING + std::to_string(m_attack_damage) + POINTS, DEFAULT);
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (m_hit_points <= 0) {
        Print::PrintMessage(CLAPTRAP + m_name + " has no hit points left!", DEFAULT);
        return;
    }
    m_hit_points -= amount;
    if (m_hit_points < 0)
        m_hit_points = 0;
    Print::PrintMessage(CLAPTRAP + m_name + TAKES + std::to_string(amount) + POINTS, DEFAULT);
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (m_hit_points == 0) {
        Print::PrintMessage(CLAPTRAP + m_name + " has no hit points left!", DEFAULT);
        return;
    }
    if (m_energy_points == 0) {
        Print::PrintMessage(CLAPTRAP + m_name + " has no energy left to be repaired!", DEFAULT);
        return;
    }
    m_hit_points += amount;
    if (m_hit_points > 10)
    {
        Print::PrintMessage(CLAPTRAP + m_name + " is fully repaired!", DEFAULT);
        m_hit_points = 10;
    }
    m_energy_points--;
    Print::PrintMessage(CLAPTRAP + m_name + REPAIRED + std::to_string(amount) + POINTS , DEFAULT);
}

void ClapTrap::PrintStats() const {
    std::cout << " -- Stats for " << MAGENTA <<  m_name << DEFAULT << std::endl;
    std::cout << "Hit Points: " << MAGENTA << m_hit_points << DEFAULT << std::endl;
    std::cout << "Energy Points: " << MAGENTA << m_energy_points << DEFAULT << std::endl;
    std::cout << "Attack Damage: " << MAGENTA << m_attack_damage << DEFAULT << std::endl;
}