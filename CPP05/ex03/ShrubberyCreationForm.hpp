#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#define TREE "\
          &&& &&  & &&\n\
      && &\\/&\\|& ()|/ @, &&\n\
      &\\/(/&/&||/& /_/)_&/_&\n\
   &() &\\/&|()|/&\\/ '%\" & ()\n\
  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
     &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n\
              `\\"

class ShrubberyCreationForm : public AForm {
    private:
        std::string m_target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);

        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

        virtual void execute(Bureaucrat const &executor) const;
};

#endif