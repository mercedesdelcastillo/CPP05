#include "RobotomyRequestForm.hpp"
#include <cstdlib>

//Constructors
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", "default target", 72, 45)
{
    std::cout << "A Robotomy Default Form was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
    std::cout << "A Robotomy with Target Form was created" << std::endl;
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
        this->setTarget(other.getTarget());

    }
    return (*this);
}

// Public Methods
void RobotomyRequestForm::action() const
{
    srand(time(0));
    int chance = rand() % 2;
    if(chance == 1)
    {
        std::cout << ">>>DrilliNg NoiSEssSseESsSSsS<<<" << std::endl;
        std::cout << this->getTarget() << " has been robotomized" << std::endl;
    }
    else
        std::cout << "Best luck next time robotomizing " << this->getTarget() << std::endl;
    return;
}

// Getters

// Setters



