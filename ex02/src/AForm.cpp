#include "AForm.hpp"
#include "Bureaucrat.hpp"


//Constructors
AForm::AForm(void) : _name("Default"), _signed(false), _signgrade(150), _execgrade(150)
{
    std::cout << "A new Default Aform was created" << std::endl;
}

AForm::AForm(std::string name, int signgrade, int execgrade) : _name(name), _signgrade(signgrade), _execgrade(execgrade)
{
    this->_signed = false;
    if(signgrade < 1 || execgrade < 1)
            throw GradeTooHighException();
    else if(signgrade > 150 || execgrade > 150)
        throw GradeTooLowException();
    std::cout << "A concrete form was created" << std::endl;
    return;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signgrade(other._signgrade), _execgrade(other._execgrade)
{
    std::cout << "The Aform was copied" << std::endl;
}
// Destructors
AForm::~AForm(void)
{
    std::cout << "The Aform was destroyed" << std::endl;
}

// Overload Operators
AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Not a good idea, but the Aforms are a bit equal now" << std::endl;
    if(this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

// Public Methods
bool AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= this->getSigngrade())
    {
        this->setSigned(true);
        return true;
    }
    std::cout << "Bureaucrat does not have the apropiate grade" << std::endl;
    return false;
}
// Getters
std::string const &AForm::getName(void) const
{
    return(_name);
}

bool AForm::getSigned(void) const
{
    return (_signed);
}
int AForm::getSigngrade(void) const
{
    return (_signgrade);
}
int AForm::getExecgrade(void) const
{
    return (_execgrade);
}

// Setters
void AForm::setSigned(bool state)
{
    this->_signed = state;
}

std::ostream& operator<<(std::ostream& out, const AForm &form)
{
    out << "The form " << form.getName() << " needs a bureaucrat of grade " << form.getSigngrade() <<
        " to be signed and a bureaucrat of grade "<< form.getExecgrade() << " to be executed" << std::endl;
    if(form.getSigned())
        out << "This form has already been signed" << std::endl;
    else
        out << "This form needs to be signed" << std::endl;
    return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Exception! Grade too high for a form!");
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Exception! Grade too low for a form!");
}

