#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "define.hpp"
#include <iostream>

class PhoneBook {
private:
    Contact m_contacts[MAX_CONTACTS];
    int m_index;

public:
    // Constructor of the PhoneBook class
	PhoneBook();

    // Destructor of the PhoneBook class
	~PhoneBook();

    // Save a new contact
	void addContact();

    // Display a specific contact
	void searchContact(int index) const;

	// Close the phonebook
	void closePhoneBook();
};


#endif
