#include "RobotomyRequestForm.hpp"
#include <cstdlib>

//Constructors
RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
    std::cout << "A Robotomy Default Form was created" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string name, int signgrade, int execgrade) : AForm(name, signgrade, execgrade)
{
    if(signgrade < 1 || execgrade < 1)
        throw GradeTooHighException();
    else if(signgrade > 72 || execgrade > 45)
        throw GradeTooLowException();
    std::cout << "Robotomy with Atributes Form was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    std::cout << "Robotomy Copy constructor called" << std::endl;
}
// Destructors
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Robotomy Destructor called" << std::endl;
}

// Overload Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "Not a good idea, but the Shrubbery Forms are a bit equal now" << std::endl;
    if(this != &other)
    {
        this->setSigned(other.getSigned());
    }
    return (*this);
}

// Public Methods
void RobotomyRequestForm::action(std::string target)
{
    srand(time(0));
    int chance = rand() % 2;
    if(chance == 1)
    {
        std::cout << ">>>DrilliNg NoiSEssSseESsSSsS<<<" << std::endl;
        std::cout << target << " has been robotomized" << std::endl;
    }
    else
        std::cout << "Best luck next time robotomizing!" << std::endl;
}

// Getters

// Setters



