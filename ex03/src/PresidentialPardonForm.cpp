#include "PresidentialPardonForm.hpp"

//Constructors
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", "default target", 25, 5)
{
    std::cout << "A Presidential Default Form was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
    std::cout << "A Presidential with Target Form was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    std::cout << "Presidential Copy constructor called" << std::endl;
}
// Destructors
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Presidential Destructor called" << std::endl;
}

// Overload Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "Not a good idea, but the Presidential Forms are a bit equal now" << std::endl;
    if(this != &other)
    {
        this->setSigned(other.getSigned());
        this->setTarget(other.getTarget());
    }
    return (*this);
}

// Public Methods
void PresidentialPardonForm::action() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    return;
}

// Getters

// Setters



