#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string m_target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &copy);

    virtual ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

    virtual void execute(Bureaucrat const &executor) const;
};

#endif