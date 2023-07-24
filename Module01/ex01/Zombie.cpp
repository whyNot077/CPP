# include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << BLACK << this->m_name << ZOMBIE_DEAD << std::endl;
}

void Zombie::announce() const {
    std::cout << RED << this->m_name << ZOMBIE_BRAINS << DEFAULT << std::endl;
}

void Zombie::SetName(std::string name) {
    this->m_name = name;
    std::cout << GREEN << this->m_name << ZOMBIE_BORN << GREEN << std::endl;
}
