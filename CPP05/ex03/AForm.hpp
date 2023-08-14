#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#define GRADE_TOO_HIGH "Grade is too high"
#define GRADE_TOO_LOW "Grade is too low"

class Bureaucrat;

class AForm {
private:
    const std::string m_name;
    bool m_signed;
    const int m_signGrade;
    const int m_execGrade;

public:
    AForm();
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm& operator=(const AForm& other);
    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class AlreadySignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class NotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif