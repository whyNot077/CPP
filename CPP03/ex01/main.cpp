#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "Print.hpp"
#include <iostream>

int main() {
    ScavTrap* scav = new ScavTrap("Scav");
    for (int i = 0; i < 3; i++) {
        scav->takeDamage(20);
    }
    scav->PrintStats();
    for (int i = 0; i < 5; i++) {
        scav->beRepaired(20);
    }
    scav->PrintStats();
    for (int i = 0; i < 6; i++) {
        scav->attack("enemy");
    }
    scav->PrintStats();
    delete scav;
    return 0;
}
