#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <limits>
#include <iostream>
#include "define.hpp"

class Contact {
private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_nickname;
    std::string m_phoneNumber;
    std::string m_darkestSecret;

	void DisplayOnlyTenChar(const std::string& str) const;

    // get contact information from user
	std::string GetContactInfo(const std::string& message);

    int CinError() const;

public:
	// display the contact using matrix, and only display 10 characters
	void DisplayContact(const int index) const;

	// get the contact
	void GetContact();

	// display the contact, not summarize the information
	void DisplayFullContact(const int index) const;
};

#endif
