#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
class ICharacter;

class AMateria
{
protected:
    std::string m_type;

public:
    AMateria() {}
    AMateria(std::string const & type) {m_type = type;}
    AMateria(const AMateria& other) {*this = other;}
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria() {}
    std::string const & getType() const;
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
