#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form form("Form", 1, 1);
    try {
        Bureaucrat Sherlock("Sherlock", 1);
        Sherlock.signForm(form);
        Sherlock.incrementGrade();
        Sherlock.signForm(form);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat Watson("Watson", 150);
        Watson.signForm(form);
        Watson.incrementGrade();
        Watson.signForm(form);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat Conan("Conan", 2);
        Conan.signForm(form);
        Conan.incrementGrade();
        Conan.signForm(form);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
