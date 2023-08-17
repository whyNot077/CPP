#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer {
private:
    Serializer() {}
    ~Serializer() {}
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& copy);

public:
    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
};


#endif
