#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
    //Constructors
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string name, int signgrade, int execgrade);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);

    //Destructors
        ~ShrubberyCreationForm();

    //Overload Operators
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    
    //Public Methods
        void create_file(std::string name);
    //Setters

    //Getters
        
};

#endif

