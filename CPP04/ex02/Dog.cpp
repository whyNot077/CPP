#include "Dog.hpp"

static int talkative = 5;

Dog::Dog() : Animal(){
    m_type = "Dog";
    m_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    m_type = other.getType();
    m_brain = new Brain(*other.m_brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete m_brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete m_brain;
        m_brain = new Brain(*other.m_brain);
    }
    return *this;
}

void Dog::makeSound() const {
    if (m_brain->getIdea(0) == "") {
        std::cout << BLUE << "Woof Woof!" << DEFAULT << std::endl;
        return;
    }
    for (int i = 0; i < talkative; i++) {
        std::cout << BLUE << m_brain->getIdea(i) << DEFAULT << std::endl;
    }
}

void Dog::think() const {
    int count;
    std::string *ideas = split(DOG_IDEA, ',', count);
    for (int i = 0; i < 100; i++) {
        int index = std::rand() % count;
        m_brain->setIdea(i, ideas[index]);
    }
    delete[] ideas;
}