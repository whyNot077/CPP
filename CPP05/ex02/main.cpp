#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void sign_and_execute_all_forms(Bureaucrat& bureau, PresidentialPardonForm& presential, RobotomyRequestForm& robotomy, ShrubberyCreationForm& shrubbery) {
    bureau.signForm(presential);
    bureau.executeForm(presential);
    bureau.signForm(robotomy);
    bureau.executeForm(robotomy);
    bureau.signForm(shrubbery);
    bureau.executeForm(shrubbery);
}

int main()
{
    PresidentialPardonForm presential("power overwelming");
    RobotomyRequestForm robotomy("show me the money");
    ShrubberyCreationForm shrubbery("black sheep wall");

    try {
        Bureaucrat Sherlock("Sherlock", 1);
        sign_and_execute_all_forms(Sherlock, presential, robotomy, shrubbery);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat Watson("Watson", 137);
        sign_and_execute_all_forms(Watson, presential, robotomy, shrubbery);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat Conan("Conan", 70);
        sign_and_execute_all_forms(Conan, presential, robotomy, shrubbery);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
