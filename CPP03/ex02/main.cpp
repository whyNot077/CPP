#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "Print.hpp"
#include <iostream>

int main() {
    FragTrap* frag = new FragTrap("frag");
    for (int i = 0; i < 3; i++) {
        frag->takeDamage(20);
    }
    frag->PrintStats();
    for (int i = 0; i < 5; i++) {
        frag->beRepaired(20);
    }
    frag->PrintStats();
    for (int i = 0; i < 6; i++) {
        frag->attack("enemy");
    }
    frag->PrintStats();
    frag->highFivesGuys();
    delete frag;
    return 0;
}
