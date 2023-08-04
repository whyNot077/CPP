#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#define GRADE_TOO_HIGH "Grade is too high"
#define GRADE_TOO_LOW "Grade is too low"

class Bureaucrat;

class Form {
private:
    const std::string m_name;
    bool m_signed;
    const int m_signGrade;
    const int m_execGrade;

public:
    Form();
    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form& other);
    ~Form();
    Form& operator=(const Form& other);
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    const std::string& getName() const;

    // change m_signed value to true
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // if bureaucrat's grade is higher than m_signGrade, can sign the form
    void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif