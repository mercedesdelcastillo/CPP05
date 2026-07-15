#include "RobotomyRequestForm.hpp"

//Constructors
RobotomyRequestForm::RobotomyRequestForm(void)
{
    std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
}
// Destructors
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Destructor called" << std::endl;
}

// Overload Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Public Methods

// Getters

// Setters



