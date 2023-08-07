#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include "Data.hpp"

class Serializer {
private:
    Serializer() {}
    ~Serializer() {}
    Serializer(const Serializer& copy) { (void)copy; }
    Serializer& operator=(const Serializer& copy) { (void)copy; return *this;}

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};


#endif
