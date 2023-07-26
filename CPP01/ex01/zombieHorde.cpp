#include "Zombie.hpp"

std::string* split(const std::string& str, char delim, int& count) {
    std::string* words;
    count = 0;
    size_t start = 0;
    size_t end = str.find(delim);

    while (end != std::string::npos) {
        count++;
        start = end + 1;
        end = str.find(delim, start);
    }

    words = new std::string[count];
    start = 0;
    end = str.find(delim);
    int i = 0;

    while (end != std::string::npos) {
        words[i] = str.substr(start, end - start);
        i++;
        start = end + 1;
        end = str.find(delim, start);
    }

    return words;
}

std::string name_with_id(std::string &name) {
    int count;
    std::string* characters = split(ZOMBIE_CHARACTERS, ',', count);
    int index = std::rand() % count;
    std::string new_name = characters[index] + "_" + name;
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
