#include "ClapTrap.hpp"
#include "Print.hpp"

int main() {
    ClapTrap clap("hello");
    ClapTrap clap2(clap);
    ClapTrap clap3("new");
    clap3 = clap2;
    for (int i = 0; i < 3; i++) {
        clap.takeDamage(3);
    }
    clap.PrintStats();
    for (int i = 0; i < 6; i++) {
        clap.beRepaired(10);
    }
    clap.PrintStats();
    for (int i = 0; i < 6; i++) {
        clap.attack("enemy");
    }
    clap.PrintStats();
    return 0;
}