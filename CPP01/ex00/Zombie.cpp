# include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    m_name = name;
    std::cout << GREEN << m_name << ZOMBIE_BORN << GREEN << std::endl;
}

Zombie::~Zombie() {
    std::cout << BLACK << m_name << ZOMBIE_DEAD << std::endl;
}

void Zombie::announce() const {
    std::cout << RED << m_name << ZOMBIE_BRAINS << DEFAULT << std::endl;
}
