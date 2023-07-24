# define STRING_VARIABLE "HI THIS IS BRAIN"
# define STRING "string: "
# define STRINGPTR "stringPTR: "
# define STRINGREF "stringREF: "
# define ADDRESS " << The memory address of >> "
# define ADDRESS_HELD " << The memory address held by >> "
# define VALUE " << The value >>"
# define BLUE "\033[34m"
# define DEFAULT "\033[0m"
# define CYAN "\033[36m"
# include <iostream>

int main() {
    std::string string = STRING_VARIABLE;
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << BLUE << ADDRESS << DEFAULT << std::endl;
    std::cout << CYAN << STRING << DEFAULT << &string << std::endl;
    std::cout << CYAN << STRINGPTR << DEFAULT << &stringPTR << std::endl;
    std::cout << CYAN << STRINGREF << DEFAULT << &stringREF << std::endl << std::endl;

    std::cout << BLUE << ADDRESS_HELD << DEFAULT << std::endl;
    std::cout << CYAN << STRING << DEFAULT << &string << std::endl;
    std::cout << CYAN << STRINGPTR << DEFAULT << stringPTR << std::endl;
    std::cout << CYAN << STRINGREF << DEFAULT << &stringREF << std::endl << std::endl;

    std::cout << BLUE << VALUE << DEFAULT << std::endl;
    std::cout << CYAN << STRING << DEFAULT << string << std::endl;
    std::cout << CYAN << STRINGPTR << DEFAULT << *stringPTR << std::endl;
    std::cout << CYAN << STRINGREF << DEFAULT << stringREF << std::endl << std::endl;

    return 0;
}
