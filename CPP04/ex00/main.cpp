#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "My type is " << YELLOW << i->getType() << DEFAULT << std::endl;
    std::cout << "My type is " << YELLOW << j->getType() << DEFAULT << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "My type is " << YELLOW << wrongCat->getType() << DEFAULT << std::endl;
    std::cout << "My type is " << YELLOW << wrongMeta->getType() << DEFAULT << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;
    return 0;
}