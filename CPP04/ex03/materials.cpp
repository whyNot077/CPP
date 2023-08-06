#include "includes.hpp"

AMateria** make_material_array(int size) {
    AMateria** materia = new AMateria*[size];
    for (int i = 0; i < size; i++)
        materia[i] = nullptr;
    return materia;
}

static int get_dynamic_array_length(AMateria** array) {
    int length = 0;
    while (array[length] != nullptr) {
        length++;
    }
    return length;
}

AMateria** extend_material_array(AMateria** materia) {
    int length = get_dynamic_array_length(materia);
    AMateria** extended = new AMateria*[length * 2];
    for (int i = 0; i < length; i++) 
        extended[i] = materia[i];
    for (int i = length; i < length * 2; i++) 
        extended[i] = nullptr;
    delete[] materia;
    return extended;
}

void copy_materials(AMateria** const source, AMateria** destination) {
    int length = get_dynamic_array_length(source);
    for (int i = 0; i < length; i++) {
        if (source[i] != nullptr)
            destination[i] = source[i]->clone();
        else
            destination[i] = nullptr;
    }
}

AMateria** new_copy_slots(AMateria* const materia[4]) {
    AMateria** copy = new AMateria*[4];
    for (int i = 0; i < 4; i++) {
        if (materia[i] != nullptr)
            copy[i] = materia[i]->clone();
        else
            copy[i] = nullptr;
    }
    return copy;
}

void delete_slots(AMateria* materia[4]) {
    for (int i = 0; i < 4; i++) {
        if (materia[i] != nullptr) {
            delete materia[i];
            materia[i] = nullptr;
        }
    }
}
