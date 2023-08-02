#include "includes.hpp"

IMateriaSource::IMateriaSource() {
    for (int i = 0; i < 4; i++)
        m_materials[i] = nullptr;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
    copy_materials(other.m_materials, m_materials);
    std::cout << "IMateriaSource copy constructor called" << std::endl;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {
    std::cout << "IMateriaSource assignation operator called" << std::endl;
    if (this != &other) {
        delete_materials(m_materials);
        copy_materials(other.m_materials, m_materials);
    }
    return *this;
}
