#include "Harl.hpp"

void Harl::debug(void) { 
    std::cout << GREEN << DEBUG_MSG << DEFAULT << std::endl;
}

void Harl::info(void) {
    std::cout << BLUE << INFO_MSG << DEFAULT << std::endl;
}

void Harl::warning(void) {
    std::cout << YELLOW << WARNING_MSG << DEFAULT << std::endl;
}

void Harl::error(void) {
    std::cout << RED << ERROR_MSG << DEFAULT << std::endl;
}

void Harl::other(void) {
    std::cout << MAGENTA << INSIGNIFICANT << DEFAULT << std::endl;
}

Harl::Harl() {
    m_complain_func[0] = &Harl::debug;
    m_complain_func[1] = &Harl::info;
    m_complain_func[2] = &Harl::warning;
    m_complain_func[3] = &Harl::error;
    m_complain_func[4] = &Harl::other;
}

ComplaintLevel Harl::get_index(std::string level) {
    if (level == DEBUG)
        return Debug;
    else if (level == INFO)
        return Info;
    else if (level == WARNING)
        return Warning;
    else if (level == ERROR)
        return Error;
    else
        return Other;
}

void Harl::complain(std::string level) {
    ComplaintLevel index = get_index(level);
    switch (index)
    {
        case Other:
        {
            (this->*m_complain_func[4])();
            break;
        }
        case Debug:
            (this->*m_complain_func[0])();
        case Info:
            (this->*m_complain_func[1])();
        case Warning:
            (this->*m_complain_func[2])();
        case Error:
            (this->*m_complain_func[3])();
    }
}
