#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : m_name("default"), m_signed(false), m_signGrade(150), m_execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade) \
    : m_name(name), m_signed(false), m_signGrade(signGrade), m_execGrade(execGrade) { }

AForm::AForm(const AForm& other) \
    : m_name(other.m_name), m_signed(other.m_signed), m_signGrade(other.m_signGrade), \
    m_execGrade(other.m_execGrade) { }

AForm::~AForm() { }

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        m_signed = other.m_signed;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return m_name;
}

bool AForm::isSigned() const {
    return m_signed;
}

int AForm::getSignGrade() const {
    return m_signGrade;
}

int AForm::getExecGrade() const {
    return m_execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > m_signGrade) {
        throw AForm::GradeTooLowException();
    }
    isSigned();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return GRADE_TOO_HIGH;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return GRADE_TOO_LOW;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > m_execGrade) {
        throw AForm::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "** info on form " << form.getName() << " **" << std::endl;
    out << "signed: " << form.isSigned() << std::endl;
    out << "sign grade: " << form.getSignGrade() << std::endl;
    out << "exec grade: " << form.getExecGrade() << std::endl;
    return out;
}