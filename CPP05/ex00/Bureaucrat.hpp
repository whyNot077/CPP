#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define EXCEPTION_HIGH "Error: Grade is too high"
#define EXCEPTION_LOW "Error: Grade is too low"
#define PROMOTE "promoted"
#define DEMOTE "demoted"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[0m"

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string m_name;
    int m_grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat() {}
    Bureaucrat& operator=(const Bureaucrat& other);
    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
