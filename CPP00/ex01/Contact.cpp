# include "custom.hpp"

void Contact::DisplayOnlyTenChar(const std::string& str) const {
	int printSpace;

	printSpace = 10 - str.length();
    std::cout << '|';
	if (printSpace < 0) {
		std::cout << str.substr(0, 9) << '.';
	} else {
		for (int i = 0; i < printSpace; i++) {
			std::cout << ' ';
		}
		std::cout << str;
	}
}

void Contact::DisplayContact(const int index) const {
    Print::PrintMessage(DISPLAY_FIRST_LINE, DEFAULT);
    DisplayOnlyTenChar(std::to_string(index));
    DisplayOnlyTenChar(m_firstName);
	DisplayOnlyTenChar(m_lastName);
	DisplayOnlyTenChar(m_nickname);
    Print::PrintMessage("|", DEFAULT);
    Print::PrintMessage(DISPLAY_LAST_LINE, DEFAULT);
}

std::string Contact::GetContactInfo(const std::string& message) {
    std::string info;

    info = GetInput::GetValidCommand(message, CYAN);
    return info;
}

void Contact::GetContact() {
    Print::PrintMessage(GET_NEW_CONTACT, YELLOW);
	m_firstName = GetContactInfo(GET_FIRST_NAME);
	m_lastName = GetContactInfo(GET_LAST_NAME);
	m_nickname = GetContactInfo(GET_NICKNAME);
	m_phoneNumber = GetContactInfo(GET_PHONE_NUMBER);
	m_darkestSecret = GetContactInfo(GET_DARKEST_SECRET);
    Print::PrintMessage(GET_CONTACT_SUCCESS, YELLOW);
}

void Contact::DisplayFullContact(const int index) const {
    Print::PrintMessage(DISPLAY_CONTACT, DEFAULT);
    
    Print::PrintMessage(DISPLAY_CONTACT, DEFAULT);
	std::cout << DISPLAY_FIRST_NAME << m_firstName << std::endl;
	std::cout << DISPLAY_LAST_NAME << m_lastName << std::endl;
	std::cout << DISPLAY_NICKNAME << m_nickname << std::endl;
	std::cout << DISPLAY_PHONE_NUMBER << m_phoneNumber << std::endl;
	std::cout << DISPLAY_DARKEST_SECRET << m_darkestSecret << std::endl;
    Print::PrintMessage(DISPLAY_CONTACT, DEFAULT);
}