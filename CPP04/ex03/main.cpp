#include "includes.hpp"

void leaks() {
    system("leaks materia");
}

int main()
{
    atexit(leaks);
    std::srand(static_cast<unsigned int>(std::time(0)));
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    for (int i = 0; i < 3; i++) {
        if (rand() % 2)
            tmp = src->createMateria("cure");
        else
            tmp = src->createMateria("ice");
        me->equip(tmp);
    }
    tmp = src->createMateria("bob");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    for (int i = 0; i < 4; i++) {
        me->use(i, *bob);
    }
    me->unequip(0);
    delete bob;
    delete me;
    delete src;
    return 0;
}