#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
    //Constructors
        Intern(void);
        Intern(const Intern& other);
    //Destructors
        ~Intern();
    //Overload Operators
        Intern &operator=(const Intern &other);    
    //Public Methods
        AForm *makeForm(std::string name, std::string target);    
    //Setters
    //Getters       
};

#endif

