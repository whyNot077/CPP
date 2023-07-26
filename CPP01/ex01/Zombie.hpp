#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string m_name;

public:
    // destructor
    ~Zombie();

    // announce themselves, name : BraiiiiiiinnnzzzZ...
    void announce() const;

    // set name
    void SetName(std::string name);
};

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[0m"

#define ZOMBIE_DEAD " is dead."
#define ZOMBIE_BORN " is born."
#define ZOMBIE_BRAINS " : BraiiiiiiinnnzzzZ..."
#define ZOMBIE_NAME "Zombie"
#define ZOMBIE_CHARACTERS "strong, stupid, genious, slow, fast, hungry, angry, ugly, smelly, rotten, \
creazy, mad, insane, dangerous, creepy, spooky, hairy, dirty, \
filthy, disgusting, terrifying, horrible, terrible, awful, \
shouting, screaming, moaning, groaning, howling, growling, \
wounded, injured, bleeding, limping, crawling, staggering, \
running, walking, shambling, lurching, stumbling, \
limping, dragging, shuffling, hobbling, lurching"
#define NUMBER_OF_ZOMBIE 7

#endif
