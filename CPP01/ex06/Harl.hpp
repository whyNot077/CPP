#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#define DEBUG_MSG "[ DEBUG ]\n\
I love to get extra bacon \
for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
#define INFO_MSG "[ INFO ]\n\
I cannot believe adding extra bacon cost more money. \
You don't put enough bacon in my burger. If you did, I wouldn’t be asking for more!\n"
#define WARNING_MSG "[ WARNING ]\n\
I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years whereas you started working here since last month.\n"
#define ERROR_MSG "[ ERROR ]\n\
This is unacceptable! I want to speak to the manager now.\n"
#define INSIGNIFICANT "[ Probably complaining about insignificant problems ]"
#define DEBUG "DEBUG"
#define INFO "INFO"
#define WARNING "WARNING"
#define ERROR "ERROR"
#define GOOD "GOOD"
#define USEGE "Usage: ./harl DEBUG/INFO/WARNING/ERROR/other string"

enum ComplaintLevel {
    Debug,
    Info,
    Warning,
    Error,
    Other
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

class Harl {
private:
    typedef void (Harl::*complain_func)();
    complain_func m_complain_func[5];
    void debug();
    void info();
    void warning();
    void error();
    void other();
    ComplaintLevel get_index(std::string level);

public:
    void complain(std::string level);
    Harl();
};


#endif
