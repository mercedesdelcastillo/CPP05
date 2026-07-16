#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    public:
    //Constructors
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string name, int signgrade, int execgrade);
        PresidentialPardonForm(const PresidentialPardonForm& other);

    //Destructors
        ~PresidentialPardonForm();

    //Overload Operators
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    
    //Public Methods
    void action(std::string target);
    //Setters

    //Getters
        
};

#endif

