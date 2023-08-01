#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << CYAN << "FragTrap constructor called" << DEFAULT << std::endl;
    m_hit_points = 100;
    m_energy_points = 100;
    m_attack_damage = 30;
}

FragTrap::~FragTrap() {
    std::cout << RED << "FragTrap destructor called" << DEFAULT << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    m_name = other.m_name;
    m_attack_damage = other.m_attack_damage;
    m_hit_points = other.m_hit_points;
    m_energy_points = other.m_energy_points;
    std::cout << CYAN << "FragTrap copy constructor called" << DEFAULT << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << CYAN << "FragTrap assignation operator called" << DEFAULT << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        m_name = other.m_name;
    }
    return *this;
}

void FragTrap::attack(std::string const & target) {
    if (m_energy_points == 0) {
        std::cout << "FragTrap " << m_name << " has no energy points left!" << std::endl;
        return;
    }
    m_energy_points--;
    std::cout << GREEN << "FragTrap " << DEFAULT << m_name << " attacks " << target << " causing " << BLUE << m_attack_damage << DEFAULT << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << m_name << " has requested a high five!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (m_energy_points == 0) {
        std::cout << "FragTrap " << m_name << " has no energy points left!" << std::endl;
        return;
    }
    if (m_hit_points == 0) {
        std::cout << "FragTrap " << m_name << " has no hit points left!" << std::endl;
        return;
    }
    m_hit_points += amount;
    if (m_hit_points > 100)
        m_hit_points = 100;
    m_energy_points--;
    std::cout << YELLOW << "FragTrap " << DEFAULT << m_name << " has been repaired by " << BLUE << amount << DEFAULT << " points!" << std::endl;
}
