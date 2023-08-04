#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : m_name("default"), m_signed(false), m_signGrade(150), m_execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade) \
    : m_name(name), m_signed(false), m_signGrade(signGrade), m_execGrade(execGrade) { }

Form::Form(const Form& other) \
    : m_name(other.m_name), m_signed(other.m_signed), m_signGrade(other.m_signGrade), \
    m_execGrade(other.m_execGrade) { }

Form::~Form() { }

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        m_signed = other.m_signed;
    }
    return *this;
}

const std::string& Form::getName() const {
    return m_name;
}

bool Form::isSigned() const {
    return m_signed;
}

int Form::getSignGrade() const {
    return m_signGrade;
}

int Form::getExecGrade() const {
    return m_execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > m_signGrade) {
        throw Form::GradeTooLowException();
    }
    isSigned();
}

const char* Form::GradeTooHighException::what() const throw() {
    return GRADE_TOO_HIGH;
}

const char* Form::GradeTooLowException::what() const throw() {
    return GRADE_TOO_LOW;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "** info on form " << form.getName() << " **" << std::endl;
    out << "signed: " << form.isSigned() << std::endl;
    out << "sign grade: " << form.getSignGrade() << std::endl;
    out << "exec grade: " << form.getExecGrade() << std::endl;
    return out;
}