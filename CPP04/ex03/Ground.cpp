#include "includes.hpp"

Ground::Ground() : m_size(4){
    m_ground = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        m_ground[i] = NULL;
}

Ground::Ground(const Ground& other) : m_size(other.m_size) {
    m_ground = new AMateria*[m_size];
    for (int i = 0; i < m_size; i++) {
        if (other.m_ground[i])
            m_ground[i] = other.m_ground[i]->clone();
        else
            m_ground[i] = NULL;
    }
}

Ground& Ground::operator=(const Ground& other) {
    if (this != &other) {
        clean_ground();

        m_size = other.m_size;
        m_ground = new AMateria*[m_size];
        for (int i = 0; i < m_size; i++) {
            if (other.m_ground[i])
                m_ground[i] = other.m_ground[i]->clone();
            else
                m_ground[i] = NULL;
        }
    }
    return *this;
}

void Ground::clean_ground() {
    for (int i = 0; i < m_size; i++) {
        if (m_ground[i] != NULL) {
            delete m_ground[i];
            m_ground[i] = NULL;
        }
    }
    delete[] m_ground;
}

Ground::~Ground() {
    clean_ground();
    std::cout << "Ground destructor called" << std::endl;
}

AMateria* Ground::getMateria(int idx) const {
    if (idx < 0 || idx >= m_size)
        return NULL;
    return m_ground[idx];
}

int Ground::getSize() const {
    return m_size;
}

void Ground::addMateria(AMateria* materia) {
    if (!materia)
        return;

    for (int i = 0; i < m_size; i++) {
        if (!m_ground[i]) {
            m_ground[i] = materia;
            return;
        }
    }

    int newSize = m_size * 2;
    AMateria** newGround = new AMateria*[newSize];
    for (int i = 0; i < m_size; i++) {
        newGround[i] = m_ground[i];
    }
    newGround[m_size] = materia;
    for (int i = m_size + 1; i < newSize; i++) {
        newGround[i] = NULL;
    }
    delete[] m_ground;
    m_ground = newGround;
    m_size = newSize;
}
