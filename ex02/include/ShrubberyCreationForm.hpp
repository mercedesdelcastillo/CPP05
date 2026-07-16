#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include<iostream>
#include<string>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


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
        void action(std::string target);
    //Setters

    //Getters
        
};

#endif

