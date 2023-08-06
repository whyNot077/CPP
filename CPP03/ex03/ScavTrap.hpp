#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
    std::string m_scav_name;
public:
// orthodox canonical class form
    ScavTrap(std::string name);
    virtual ~ScavTrap();
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    virtual void attack(std::string const & target);
    void guardGate();
};

#endif
