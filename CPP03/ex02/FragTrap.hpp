#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& other);
    void attack(std::string const & target);
    void highFivesGuys();
    void beRepaired(unsigned int amount);
};

#endif
