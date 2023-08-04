#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), m_target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), m_target(other.m_target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    AForm::operator=(other);
    m_target = other.m_target;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    std::cout << m_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
