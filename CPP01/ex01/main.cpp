# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    Zombie* zombies = zombieHorde(NUMBER_OF_ZOMBIE, ZOMBIE_NAME);
    for (int i = 0; i < NUMBER_OF_ZOMBIE; i++) {
        zombies[i].announce();
    }
    delete [] zombies;
    return 0;
}