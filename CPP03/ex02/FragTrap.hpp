#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
// orthodox canonical class form
    FragTrap() {}
    FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    virtual ~FragTrap();
    FragTrap& operator=(const FragTrap& other);
    virtual void attack(std::string const & target);
    void highFivesGuys();
};

#endif
