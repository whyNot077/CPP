#ifndef GROUND_HPP
#define GROUND_HPP

#include <string>
#include "AMateria.hpp"

class Ground {
protected:
    AMateria** m_ground;
    int m_size;
public:
    Ground();
    Ground(const Ground& other);
    Ground& operator=(const Ground& other);
    virtual ~Ground();
    AMateria* getMateria(int idx) const;
    int getSize() const;
    void addMateria(AMateria* materia);
    void clean_ground();
};

#endif
