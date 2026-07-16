#include "PresidentialPardonForm.hpp"

//Constructors
PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
    std::cout << "A Presidential Default Form was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int signgrade, int execgrade) : AForm(name, signgrade, execgrade)
{
    if(signgrade < 1 || execgrade < 1)
        throw GradeTooHighException();
    else if(signgrade > 25 || execgrade > 5)
        throw GradeTooLowException();
    std::cout << "A Presidential Form was created" << std::endl;
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
    }
    return (*this);
}

// Public Methods
void PresidentialPardonForm::action(std::string target)
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// Getters

// Setters



