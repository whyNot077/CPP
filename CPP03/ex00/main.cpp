#include "ClapTrap.hpp"
#include "Print.hpp"

int main() {
    ClapTrap clap("hello");
    ClapTrap clap2(clap);
    ClapTrap clap3("new");
    clap3 = clap2;
    clap.attack("target");
    for (int i = 0; i < 5; i++) {
        clap.takeDamage(1);
    }
    clap.PrintStats();
    for (int i = 0; i < 6; i++) {
        clap.beRepaired(20);
    }
    clap.PrintStats();
    return 0;
}