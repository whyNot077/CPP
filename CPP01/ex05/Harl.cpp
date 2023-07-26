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

Harl::Harl() {
    m_complain_func[0] = &Harl::debug;
    m_complain_func[1] = &Harl::info;
    m_complain_func[2] = &Harl::warning;
    m_complain_func[3] = &Harl::error;
}

int Harl::get_index(std::string level) {
    if (level == DEBUG)
        return CASE_DEBUG;
    else if (level == INFO)
        return CASE_INFO;
    else if (level == WARNING)
        return CASE_WARNING;
    else if (level == ERROR)
        return CASE_ERROR;
    else
        return CASE_OTHER;
}

void Harl::complain(std::string level) {
    int index = get_index(level);
    switch (index) {
        case CASE_DEBUG:
            (this->*m_complain_func[0])();
            break;
        case CASE_INFO:
            (this->*m_complain_func[1])();
            break;
        case CASE_WARNING:
            (this->*m_complain_func[2])();
            break;
        case CASE_ERROR:
            (this->*m_complain_func[3])();
            break;
        default:
            std::cout << "Wrong level" << std::endl;
            break;
    }
}

