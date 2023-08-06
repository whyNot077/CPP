#include "includes.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        m_materials[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.m_materials[i] != nullptr)
            m_materials[i] = other.m_materials[i]->clone();
        else
            m_materials[i] = nullptr;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (m_materials[i] != nullptr)
                delete m_materials[i];
        }
        for (int i = 0; i < 4; i++) {
            if (other.m_materials[i] != nullptr)
                m_materials[i] = other.m_materials[i]->clone();
            else
                m_materials[i] = nullptr;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (m_materials[i] != nullptr)
            delete m_materials[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia) {
    for (int i = 0; i < 4; i++) {
        if (m_materials[i] == nullptr) {
            m_materials[i] = materia;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (m_materials[i] != nullptr && m_materials[i]->getType() == type)
            return m_materials[i]->clone();
    }
    return nullptr;
}