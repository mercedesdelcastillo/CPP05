#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
    //Constructors
        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm& other);

    //Destructors
        ~PresidentialPardonForm();

    //Overload Operators
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    
    //Public Methods
    
    //Setters

    //Getters
        
};

#endif

