#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string m_target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &copy);

    virtual ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

    virtual void execute(Bureaucrat const &executor) const;
};

#endif