#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

static int max_animal = 3;
void leaks( void )
{
    system("leaks animal");
}

int main()
{
    atexit(leaks);
    std::srand(static_cast<unsigned int>(std::time(0)));
    Animal* animals[max_animal];
    for (int i = 0; i < max_animal; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << "---------------------" << std::endl;
    animals[0]->makeSound();
    animals[1]->makeSound();
    std::cout << "---------------------" << std::endl;
    for (int i = 0; i < max_animal; i++)
    {
        animals[i]->think();
        animals[i]->makeSound();
        std::cout << "---------------------" << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    for (int i = 0; i < max_animal; i++)
    {
        delete animals[i];
    }
    return 0;
}