#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "define.hpp"
#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
    Contact m_contacts[MAX_CONTACTS];
    int m_count;
    int m_numberOfContacts;

    // Get the valid index
    int GetIndex() const;

public:
    // Constructor of the PhoneBook class
    PhoneBook();

    // Destructor of the PhoneBook class
    ~PhoneBook();

    // Start the PhoneBook
    void StartPhoneBook() const;

    // Get the command, change it to uppercase, and return it
    std::string GetCommand();

    // Save a new contact
    void AddContact();

    // Display a specific contact
    void SearchContact() const;

    // Close the PhoneBook
    static void ClosePhoneBook();
};

#endif
