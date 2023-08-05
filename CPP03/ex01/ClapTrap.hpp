#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include "Print.hpp"

class ClapTrap {
protected:
    std::string m_name;
    int m_hit_points;
    int m_energy_points;
    int m_attack_damage;
    int m_max_hit_points;
    bool check_invalid_action();

public:
    // Hit points: 10, Energy points: 10, Attack damage: 0
    // Orthodox canonical class form
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& other);

    bool attack_damage(void);
    
    // Cause its target to lose <attack damage> hit points.
    // It costs 1 energy point.
    virtual void attack(std::string const & target);

    // Decrease hit points by <amount>.
    void takeDamage(unsigned int amount);

    // Increase hit points by <amount> up to a maximum of <hit points>.
    // It costs 1 energy point.
    virtual void beRepaired(unsigned int amount);

    void PrintStats();
};

#endif
