#include "includes.hpp"

void delete_materials(AMateria **materia) {
    for (int i = 0; i < 4; i++) {
        if (materia[i] != nullptr) {
            delete materia[i];
            materia[i] = nullptr;
        }
    }
}

AMateria **copy_materials(AMateria *const materia[4]) {
    AMateria **copied = new AMateria *[4];
    for (int i = 0; i < 4; i++) {
        if (materia[i])
            copied[i] = materia[i]->clone();
        else
            copied[i] = nullptr;
    }
    return copied;
}

void copy_materials(AMateria *const source[4], AMateria *destination[4]) {
    for (int i = 0; i < 4; i++) {
        if (source[i])
            destination[i] = source[i]->clone();
        else
            destination[i] = nullptr;
    }
}
