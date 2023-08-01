#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string m_name;

public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    void attack(std::string const & target);
    void beRepaired(unsigned int amount);
    void whoAmI();
};

#endif
