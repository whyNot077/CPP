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

    std::cout << "---------------------" << std::endl;
    diamondTrap.whoAmI();

    std::cout << "---------------------" << std::endl;
    DiamondTrap new_diamond("new");
    new_diamond.whoAmI();

    std::cout << "---------------------" << std::endl;
    DiamondTrap copy_diamond(new_diamond);
    copy_diamond.whoAmI();

    std::cout << "---------------------" << std::endl;
    DiamondTrap assign_diamond("assign");
    assign_diamond.whoAmI();
    assign_diamond = diamondTrap;
    assign_diamond.whoAmI();

    std::cout << "---------------------" << std::endl;
    assign_diamond.whoAmI();
    assign_diamond = new_diamond;
    assign_diamond.whoAmI();
    std::cout << "---------------------" << std::endl;

    return 0;
}
