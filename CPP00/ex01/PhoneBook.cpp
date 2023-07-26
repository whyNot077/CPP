# include "custom.hpp"

PhoneBook::PhoneBook() {
    m_count = 0;
    m_numberOfContacts = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::StartPhoneBook() const {
    Print::PrintMessage(HELLO, YELLOW);
}

std::string PhoneBook::GetCommand() {
    std::string command;

    command = GetInput::GetValidCommand(GET_COMMAND, BLUE);
    for (int i = 0; command[i]; i++) {
        command[i] = std::toupper(command[i]);
    }
    return command;
}

void PhoneBook::AddContact() {
    Contact contact;

    if (m_count == MAX_CONTACTS) {
        m_count = 0;
        m_numberOfContacts = MAX_CONTACTS;
    }
    m_contacts[m_count].GetContact();
    m_contacts[m_count].DisplayFullContact(m_count);
    m_count++;
    m_numberOfContacts++;
}

int PhoneBook::GetIndex() const{
    int index;

    while (true) {
        Print::PrintWithoutNewline(ENTER_INDEX, CYAN);
        if (GetInput::GetIndex(index)) {
            break;
        }
    }
    return index;
}


void PhoneBook::SearchContact() const {
    int index;

    index = GetIndex();
    m_contacts[index].DisplayContact(index);
}

void PhoneBook::ClosePhoneBook() {
    Print::PrintMessage(GOODBYE, MAGENTA);
    exit(0);
}
