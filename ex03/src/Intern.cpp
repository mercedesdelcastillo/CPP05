#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

//Constructors
Intern::Intern(void)
{
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    (void) other;
}
// Destructors
Intern::~Intern(void)
{
    std::cout << "Intern Destructor called" << std::endl;
}

// Overload Operators
Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern Assignment operator called" << std::endl;
    (void)other;
    return (*this);
}

// Public Methods
AForm *Intern::makeForm(std::string name, std::string target)
{
    if(name.empty() || target.empty())
        return NULL;
    int i = 0;
    std::string type_forms[] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};
    while (i < 3 && name != type_forms[i])
		i++;
    switch(i)
    {
        case 0:
            std::cout << "Intern creates " << name << std::endl;
            return(new RobotomyRequestForm(target));
        case 1:
            std::cout << "Intern creates " << name << std::endl;
           return(new ShrubberyCreationForm(target));
        case 2:
            std::cout << "Intern creates " << name << std::endl;
            return(new PresidentialPardonForm(target));
        default:
            std::cout << "Intern couldn't create " << name << std::endl;
            return NULL;
    }
}
// Getters

// Setters



