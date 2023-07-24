#ifndef WEAPON_HPP
#define WEAPON_HPP

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
#define CLUB "crude spiked club"
#define OTHER_CLUB "some other type of club"
#define ATTACK " attacks with their "
#define NO_WEAPON " has no weapon. Run away!"
#define GUN "crude spiked gun"
#define CHANGED_WEAPON " changed their weapon : "
#define NEW_HUMAN " comes to join the battle against the zombie horde!"
#define SET_WEAPON " sets their weapon to "

class Weapon {
private:
    std::string m_type;

public:

    // constructor, get type as parameter and store it in m_type
    Weapon(std::string type);

    // return a reference m_type
    const std::string& getType() const;

    // set m_type
    void setType(std::string type);
};

#endif
