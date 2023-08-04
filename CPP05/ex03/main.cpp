#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    try {
        intern.makeForm("robotomy request", "show me the money");
        intern.makeForm("presidential pardon", "power overwelming");
        intern.makeForm("shrubbery creation", "black sheep wall");
        intern.makeForm("unknown form", "unknown target");
    } catch (std::exception &e) {
        std::cout << RED << e.what() << DEFAULT << std::endl;
    }

    return 0;
}
