#ifndef INCLUDES_HPP
#define INCLUDES_HPP

#include <string>
#include <iostream>
#include "color.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void delete_materials(AMateria **materia);
void copy_materials(AMateria *const source[4], AMateria *destination[4]);
AMateria **copy_materials(AMateria *const materia[4]);

#endif