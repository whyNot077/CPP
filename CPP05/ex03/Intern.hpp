#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

#include <iostream>

class Intern {
    enum FormType { ROBOTOMY, PARDON, SHRUBBERY };
    struct FormMaker {
        std::string name;
        FormType type;
    }; 
    public:
        Intern();
        Intern(Intern const &copy);

        virtual ~Intern();
        Intern &operator=(Intern const &copy);

        AForm *makeForm(std::string const &name, std::string const &target);
        class FormNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

struct FormMaker {
    const char* name;
    AForm* (*createFunction)(const std::string&);
};

#endif
