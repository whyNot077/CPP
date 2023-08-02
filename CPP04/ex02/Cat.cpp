#include "Cat.hpp"

const int talkative = 5;

Cat::Cat() : Animal() {
    m_type = "Cat";
    m_brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    m_type = copy.getType();
    m_brain = new Brain(*copy.m_brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete m_brain;
        m_brain = new Brain(*other.m_brain);
    }
    return *this;
}

Cat::~Cat() {
    delete m_brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    if (m_brain->getIdea(0) == "") {
        std::cout << CYAN << "Meow meow" << DEFAULT << std::endl;
        return;
    }
    for (int i = 0; i < talkative; i++) {
        std::cout << CYAN << m_brain->getIdea(i) << DEFAULT << std::endl;
    }
}

void Cat::think() const {
    int count;
    std::string *ideas = split(CAT_IDEA, ',', count);
    for (int i = 0; i < 100; i++) {
        int index = std::rand() % count;
        m_brain->setIdea(i, ideas[index]);
    }
    delete[] ideas;
}
