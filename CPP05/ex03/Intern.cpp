#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    FormMaker formMakers[] = {
        { "robotomy request", ROBOTOMY },
        { "presidential pardon", PARDON },
        { "shrubbery creation", SHRUBBERY }
    };

    for (size_t i = 0; i < sizeof(formMakers) / sizeof(FormMaker); i++) {
        if (name == formMakers[i].name) {
            std::cout << "Intern creates " << BLUE << name << DEFAULT << " form" << std::endl;
            switch (formMakers[i].type) {
                case ROBOTOMY:
                    return new RobotomyRequestForm(target);
                case PARDON:
                    return new PresidentialPardonForm(target);
                case SHRUBBERY:
                    return new ShrubberyCreationForm(target);
            }
        }
    }
    
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}