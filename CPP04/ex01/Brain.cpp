#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        m_ideas[i] = "";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        m_ideas[i] = other.getIdea(i);
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignation operator called" << std::endl;
    for (int i = 0; i < 100; i++) {
        m_ideas[i] = other.getIdea(i);
    }
    return *this;
}

void Brain::setIdea(int index, std::string idea) {
    if (index < 0 || index >= 100) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    m_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        std::cout << "Invalid index" << std::endl;
        return "";
    }
    return m_ideas[index];
}
