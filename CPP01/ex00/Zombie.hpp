#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

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

class Zombie {
private:
    std::string m_name;

public:
    // constructor, get name as parameter and store it in m_name
    Zombie(std::string name);

    // destructor
    ~Zombie();

    // announce themselves, name : BraiiiiiiinnnzzzZ...
    void announce() const;
};

#endif
