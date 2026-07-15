#include "PresidentialPardonForm.hpp"

//Constructors
PresidentialPardonForm::PresidentialPardonForm(void)
{
    std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
}
// Destructors
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Destructor called" << std::endl;
}

// Overload Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Public Methods

// Getters

// Setters



