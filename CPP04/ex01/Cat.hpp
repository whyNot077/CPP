#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#define CAT_IDEA "I am the most genious cat!,I am happy,Look at me!,냥냥냥 \\ ( ^ㅅ^) /,\
난 천재야!,나눈야 해퓌~~,귀여운 날 봐!,냥냥냥 \\ ( ^ㅅ^) /,\
I will conquer the world,I am the best,냥냥냥 \\ ( ^ㅅ^) /,\
후후 닝겐들은 나에게 츄르를 바쳐라,냥냥냥 \\ ( ^ㅅ^) /"

class Cat : public Animal {
private:
    Brain* m_brain;

public:
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();
    Cat& operator=(const Cat& other);
    virtual void makeSound() const;
    virtual void think() const;
};

std::string* split(const std::string& str, char delim, int& count);

#endif
