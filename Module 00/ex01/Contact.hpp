#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include "define.hpp"

class Contact {
private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_nickname;
    std::string m_phoneNumber;
    std::string m_darkestSecret;

public:
    // Constructor of the Contact class
	Contact();

    // Destructor of the Contact class
	~Contact();

	// display the contact
	void displayContact();

	// get the contact
	Contact getContact();
};


#endif
