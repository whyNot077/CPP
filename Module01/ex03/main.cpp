# include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon(CLUB);
        HumanA bob("Bob", club);
        bob.attack();
        club.setType(OTHER_CLUB);
        bob.attack();
    }
    {
        Weapon club = Weapon(CLUB);
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType(OTHER_CLUB);
        jim.attack();

        Weapon gun = Weapon(GUN);
        jim.setWeapon(gun);
        jim.attack();

        HumanB jack("Jack", club);
        jack.attack();
    }
    return 0;
}