#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

class Serializer {
private:
    Serializer() {}
    ~Serializer() {}
    Serializer(const Serializer& copy) { (void)copy; }
    Serializer& operator=(const Serializer& copy) { (void)copy; return *this;}

public:
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};


#endif
