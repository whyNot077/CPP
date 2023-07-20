#include "custom.hpp"

int main(int argc, char **argv) {
    SignalHandler::SetupSignalHandlers();

    PhoneBook phoneBook;
    std::string command;
    if (argc != 1) {
        std::cout << INVALID_ARGUMENTS << std::endl;
        return 1;
    }
    phoneBook.StartPhoneBook();
    while (true) {
        command = phoneBook.GetCommand();
        if (command == ADD) {
            phoneBook.AddContact();
        } else if (command == SEARCH) {
            phoneBook.SearchContact();
        } else if (command == EXIT) {
            phoneBook.ClosePhoneBook();
        } else {
            Print::PrintMessage(INVALID_COMMAND, RED);
        }
    }
    return 0;
}