# include "Zombie.hpp"

#include <string>
#include <cstdlib>
#include <cstring>

char** split(const char* str, char delim, int& count) {
    count = 1;
    const char *p = str;
    while ((p = strchr(p, delim)) != NULL) {
        p++;
        count++;
    }
    char** words = new char*[count];
    for (int i = 0; i < count; i++) {
        const char *end = strchr(str, delim);
        if (end == NULL)
            end = str + strlen(str);
        words[i] = new char[end - str + 1];
        strncpy(words[i], str, end - str);
        words[i][end - str] = '\0';
        str = end;
        if (*str != '\0')
            str++;
    }
    return words;
}

std::string name_with_id(std::string &name)
{
    int count;
    char** characters = split(ZOMBIE_CHARACTERS, ',', count);
    int index = std::rand() % count;
    std::string new_name = std::string(characters[index]) + "_" + name;
    for (int i = 0; i < count; i++)
        delete[] characters[i];
    delete[] characters;
    return new_name;
}


Zombie* zombieHorde(int N, std::string name){
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombies[i].SetName(name_with_id(name));
    }
    return zombies;
}
