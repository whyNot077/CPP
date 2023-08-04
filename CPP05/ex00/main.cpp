#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat Sherlock("Sherlock", 1);
        Sherlock.incrementGrade();
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat Watson("Watson", 151);
        Watson.incrementGrade();
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Bureaucrat Conan("Conan", 2);
        Conan.incrementGrade();
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
