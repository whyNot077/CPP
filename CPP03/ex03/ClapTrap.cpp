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

ClapTrap::ClapTrap(std::string name) : m_name(name + "_clap_name"), m_hit_points(10), m_energy_points(10), m_attack_damage(0) {
    std::cout << CLAPTRAP << m_name << CREATED << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : m_name(other.m_name), m_hit_points(other.m_hit_points), m_energy_points(other.m_energy_points), m_attack_damage(other.m_attack_damage) {
    std::cout << CLAPTRAP << m_name << COPIED << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this == &other)
        return *this;
    m_name = other.m_name;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    m_attack_damage = other.m_attack_damage;
    std::cout << CLAPTRAP << m_name << " is now " << other.m_name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << CLAPTRAP << m_name << DESTROYED << std::endl;
}

void ClapTrap::attack(std::string const & target) {
    if (m_energy_points == 0) {
        std::cout << CLAPTRAP << m_name << " has no energy left to attack!" << std::endl;
        return;
    }
    m_energy_points--;
    std::cout << CLAPTRAP << m_name << ATTACK << target << CAUSING << m_attack_damage << POINTS << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (m_hit_points == 0) {
        std::cout << CLAPTRAP << m_name << " has no hit points left!" << std::endl;
        return;
    }
    m_hit_points -= amount;
    std::cout << CLAPTRAP << m_name << TAKES << amount << POINTS << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (m_hit_points == 0) {
        std::cout << CLAPTRAP << m_name << " has no hit points left!" << std::endl;
        return;
    }
    if (m_energy_points == 0) {
        std::cout << CLAPTRAP << m_name << " has no energy left to be repaired!" << std::endl;
        return;
    }
    m_hit_points += amount;
    if (m_hit_points > 10)
        m_hit_points = 10;
    m_energy_points--;
    std::cout << CLAPTRAP << m_name << REPAIRED << amount << POINTS << std::endl;
}

void ClapTrap::PrintStats() {
    std::cout << " -- Stats for " << m_name << std::endl;
    std::cout << "Hit Points: " << m_hit_points << std::endl;
    std::cout << "Energy Points: " << m_energy_points << std::endl;
    std::cout << "Attack Damage: " << m_attack_damage << std::endl;
}
