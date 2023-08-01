#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "Print.hpp"
#include <iostream>

int main() {
    ScavTrap* scav = new ScavTrap("Scav");
    FragTrap* frag = new FragTrap("Frag");
    ClapTrap* pointerToScav = scav;
    ClapTrap* pointerToFrag = frag;
    
    Print::PrintMessage("FragTrap's attack:", BLACK);
    frag->attack("Target");

    Print::PrintMessage("ScavTrap's attack:", BLACK);
    scav->attack("Target");

    Print::PrintMessage("ClapTrap's attack with ScavTrap's pointer:", BLACK);
    pointerToScav->attack("Target");

    Print::PrintMessage("ClapTrap's attack with FragTrap's pointer:", BLACK);
    pointerToFrag->attack("Target");

    scav->PrintStats();
    frag->PrintStats();

    delete scav;
    delete frag;
    return 0;
}
