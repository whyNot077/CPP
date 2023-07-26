#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#define DEBUG_MSG "I love to get extra bacon \
for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon cost more money. \
You don't put enough bacon in my burger. If you did, I wouldn’t be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."
#define DEBUG "debug"
#define INFO "info"
#define WARNING "warning"
#define ERROR "error"
#define GOOD "good"

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
