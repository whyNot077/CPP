# include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    Zombie* zombie1 = newZombie("Heap_Zombie");
    zombie1->announce();

    Zombie zombie2("Stack_Zombie");
    zombie2.announce();

    randomChump("random_Chump");
    delete zombie1;
    return 0;
}
