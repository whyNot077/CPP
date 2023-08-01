#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clapTrap("CT");
    FragTrap fragTrap("FT");
    ScavTrap scavTrap("ST");
    DiamondTrap diamondTrap("DT");

    ClapTrap* traps[] = { &clapTrap, &fragTrap, &diamondTrap, &scavTrap };

    for (int i = 0; i < 4; i++) {
        traps[i]->attack("some_target");
    }
    return 0;
}
