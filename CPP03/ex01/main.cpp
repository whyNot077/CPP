#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "Print.hpp"
#include <iostream>

int main() {
    ClapTrap* clap = new ClapTrap("Clap");
    ScavTrap* scav = new ScavTrap("Scav");
    ClapTrap* pointerToScav = scav;

    Print::PrintMessage("Calling ClapTrap's attack:", YELLOW);
    clap->attack("Target");

    Print::PrintMessage("Calling ScavTrap's attack:", YELLOW);
    scav->attack("Target");

    Print::PrintMessage("Calling ClapTrap's attack with ScavTrap's pointer:", YELLOW);
    pointerToScav->attack("Target");

    delete clap;
    delete scav;
    return 0;
}
