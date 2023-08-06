#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ground.hpp"

class Character : public ICharacter, public Ground{
public:
    Character();
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

void copy_slots(AMateria* const source[4], AMateria* destination[4]);

#endif
