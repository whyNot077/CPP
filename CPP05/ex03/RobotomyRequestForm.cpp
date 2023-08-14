#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), m_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), m_target(other.m_target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    AForm::operator=(other);
    m_target = other.m_target;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << m_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << m_target << " robotomization failed" << std::endl;
}