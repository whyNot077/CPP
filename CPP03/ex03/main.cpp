#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "Print.hpp"
#include <iostream>

int main() {
    DiamondTrap* diamond = new DiamondTrap("diamond");
    for (int i = 0; i < 3; i++) {
        diamond->takeDamage(20);
    }
    diamond->PrintStats();
    for (int i = 0; i < 5; i++) {
        diamond->beRepaired(20);
    }
    diamond->PrintStats();
    for (int i = 0; i < 6; i++) {
        diamond->attack("enemy");
    }
    diamond->PrintStats();
    diamond->whoAmI();
    delete diamond;
    return 0;
}
