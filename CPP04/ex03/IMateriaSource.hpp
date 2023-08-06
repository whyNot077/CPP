#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include "AMateria.hpp"

class IMateriaSource
{
protected:
    AMateria* m_materials[4];
    IMateriaSource() {}
    IMateriaSource(const IMateriaSource& other) {(void)other;}
    IMateriaSource& operator=(const IMateriaSource& other) {(void)other; return *this;}
public:
    virtual ~IMateriaSource();
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
