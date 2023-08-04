#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : m_name("default"), m_grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : m_name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : m_name(other.m_name) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        m_grade = other.m_grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return m_name;
}

int Bureaucrat::getGrade() const {
    return m_grade;
}

void Bureaucrat::incrementGrade() {
    if (m_grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    m_grade--;
    std::cout << m_name << " has been " PROMOTE << std::endl;
    std::cout << *this << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (m_grade + 1 > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    m_grade++;
    std::cout << m_name << " has been " DEMOTE << std::endl;
    std::cout << *this << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return EXCEPTION_HIGH;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return EXCEPTION_LOW;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << CYAN << bureaucrat.getName() + ","<< DEFAULT << \
        " bureaucrat grade " << CYAN << bureaucrat.getGrade() << DEFAULT << ".";
    return out;
}

void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << BLUE <<  m_name << " signed " << form.getName() << DEFAULT << std::endl;
    } catch (AForm::GradeTooLowException& e) {
        std::cout << RED << m_name << DEFAULT << " couldn't sign " << \
            form.getName() << " because " << RED << e.what() << DEFAULT << std::endl;
    } 
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << BLUE << m_name << " executed " << form.getName() << DEFAULT << std::endl;
    } catch (AForm::GradeTooLowException& e) {
        std::cout << RED << m_name << DEFAULT << " couldn't execute " << \
            form.getName() << " because " << RED << e.what() << DEFAULT << std::endl;
    } catch (AForm::GradeTooHighException& e) {
        std::cout << RED << m_name << DEFAULT << " couldn't execute " << \
            form.getName() << " because " << RED << e.what() << DEFAULT << std::endl;
    }
}