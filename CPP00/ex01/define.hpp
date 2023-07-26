#ifndef DEFINE_HPP
#define DEFINE_HPP

# define MAX_CONTACTS 8
# define INVALID_INDEX "Index should be between 0 and 7"
# define NO_CONTACT "No contact at this index"
# define NO_CONTACTS "No contacts in the phonebook"
# define INVALID_COMMAND "Invalid command : You should enter ADD, SEARCH or EXIT"
# define INVALID_INPUT "Invalid input : You should enter a printable character"
# define CLOSE "Close the phonebook"
# define OPEN "Open the phonebook"
# define ADD_CONTACT "Add a new contact"
# define EMPTY_INPUT "You should enter something"
# define SPACE_INPUT "You should enter characters"
# define HELLO "Hello, I'm your phonebook\n\n\
You can use the following commands:\n\
ADD: Add a new contact\n\
SEARCH: Search a contact\n\
EXIT: Close the PhoneBook\n\n\
What do you want to do?\n"
# define GOODBYE "\nClose the phonebook, nice to see you again"
# define GET_COMMAND "Enter a command: "
# define ADD "ADD"
# define SEARCH "SEARCH"
# define EXIT "EXIT"
# define ENTER_INDEX "Enter the index of the contact: "

# define DISPLAY_FIRST_LINE "\n\
 ___________________________________________\n\
|     Index|First Name| Last Name|  Nickname|\n\
|__________|__________|__________|__________|\n"
# define DISPLAY_LAST_LINE "\
|__________|__________|__________|__________|\n"

# define GET_NEW_CONTACT "\nLet's add a new contact"
# define GET_FIRST_NAME "Enter the first name: "
# define GET_LAST_NAME "Enter the last name: "
# define GET_NICKNAME "Enter the nickname: "
# define GET_PHONE_NUMBER "Enter the phone number: "
# define GET_DARKEST_SECRET "Enter the darkest secret: "
# define GET_CONTACT_SUCCESS "Contact added successfully"
# define DISPLAY_CONTACT "________________________________________"
# define DISPLAY_INDEX "Index: "
# define DISPLAY_FIRST_NAME "First name: "
# define DISPLAY_LAST_NAME "Last name: "
# define DISPLAY_NICKNAME "Nickname: "
# define DISPLAY_PHONE_NUMBER "Phone number: "
# define DISPLAY_DARKEST_SECRET "Darkest secret: "
# define INVALID_ARGUMENTS "Invalid arguments : You should write only ./phonebook"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[0m"

#endif
