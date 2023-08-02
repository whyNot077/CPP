#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void leaks() {
    system("leaks animal");
}

int main()
{
    atexit(leaks);
    std::srand(static_cast<unsigned int>(std::time(0)));
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << "---------------------" << std::endl;
    dog->makeSound();
    cat->makeSound();
    std::cout << "---------------------" << std::endl;
    cat->think();
    dog->think();
    dog->makeSound();
    cat->makeSound();
    std::cout << "---------------------" << std::endl;
    
    delete dog;
    delete cat;
}