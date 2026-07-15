#include "Form.hpp"

//Constructors
Form::Form(void) : _name("Default"), _signed(false), _signgrade(150), _execgrade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int signgrade, int execgrade) : _name(name), _signgrade(signgrade), _execgrade(execgrade)
{
    this->_signed = false;
    std::cout << "Parametric Form constructor called" << std::endl;
}


Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signgrade(other._signgrade), _execgrade(other._execgrade)
{
    std::cout << "Copy constructor called" << std::endl;
}
// Destructors
Form::~Form(void)
{
    std::cout << "Destructor called" << std::endl;
}

// Overload Operators
Form &Form::operator=(const Form &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if(this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

// Public Methods
bool Form::beSigned(Bureaucrat &bureaucrat)
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
std::string Form::getName(void) const
{
    return(this->_name);
}

bool Form::getSigned(void) const
{
    return (this->_signed);
}
int Form::getSigngrade(void) const
{
    return (this->_signgrade);
}
int Form::getExecgrade(void) const
{
    return (this->_execgrade);
}

// Setters
void Form::setSigned(bool state)
{
    this->_signed = state;
}

std::ostream& operator<<(std::ostream& out, const Form &form)
{
    out << "The form " << form.getName() << " needs a bureaucrat of grade " << form.getSigngrade() <<
        " to be signed and a bureaucrat of grade "<< form.getExecgrade() << "to be executed" << std::endl;
    if(form.getSigned())
        out << "This form has already been signed" << std::endl;
    else
        out << "This form this to be signed" << std::endl;
    return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Exception! Grade too high!");
}
const char *Form::GradeTooLowException::what() const throw()
{
    return ("Exception! Grade too low!");
}

