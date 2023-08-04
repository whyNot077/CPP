#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), m_target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), m_target(other.m_target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other);
    m_target = other.m_target;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    std::ofstream file(m_target + "_shrubbery");
    if (!file.is_open()) {
        std::cout << "Error: could not open file" << std::endl;
        return;
    }
    file << TREE << std::endl;
    file.close();
}
