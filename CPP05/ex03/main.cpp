#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    AForm* robot;
    try {
        robot = intern.makeForm("robotomy request", "show me the money");
        Bureaucrat Conan("Conan", 1);
        Conan.executeForm(*robot);
        Conan.signForm(*robot);
        Conan.signForm(*robot);
        Conan.executeForm(*robot);
        intern.makeForm("presidential pardon", "power overwelming");
        intern.makeForm("shrubbery creation", "black sheep wall");
        intern.makeForm("unknown form", "unknown target");
    } catch (std::exception &e) {
        std::cout << RED << e.what() << DEFAULT << std::endl;
    }

    return 0;
}
