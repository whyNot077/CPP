#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
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

class Brain {
private:
    std::string m_ideas[100];

public:
    Brain();
    Brain(const Brain& other);
    ~Brain();
    Brain& operator=(const Brain& other);
    void setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};

#endif
