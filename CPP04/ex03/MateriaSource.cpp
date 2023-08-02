#include "includes.hpp"

MateriaSource::MateriaSource() : IMateriaSource() { }

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other) { }

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    IMateriaSource::operator=(other);
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    delete_materials(m_materials);
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