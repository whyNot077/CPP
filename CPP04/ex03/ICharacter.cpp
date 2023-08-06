#include "includes.hpp" 

ICharacter::~ICharacter() {
    std::cout << "ICharacter deleted at: " << this << std::endl;
}