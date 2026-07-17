#include "Form.hpp"
#include "Bureaucrat.hpp"


//Constructors
Form::Form(void) : _name("Default"), _signed(false), _signgrade(150), _execgrade(150)
{
    std::cout << "A new Default form was created" << std::endl;
}

Form::Form(std::string name, int signgrade, int execgrade) : _name(name), _signgrade(signgrade), _execgrade(execgrade)
{
    this->_signed = false;
    if(signgrade < 1 || execgrade < 1)
            throw GradeTooHighException();
    else if(signgrade > 150 || execgrade > 150)
        throw GradeTooLowException();
    std::cout << "A concrete form was created" << std::endl;
    return;
}


Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signgrade(other._signgrade), _execgrade(other._execgrade)
{
    std::cout << "The form was copied" << std::endl;
}
// Destructors
Form::~Form(void)
{
    std::cout << "The form was destroyed" << std::endl;
}

// Overload Operators
Form &Form::operator=(const Form &other)
{
    std::cout << "Not a good idea, you can only copy the signed state between forms" << std::endl;
    if(this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

// Public Methods
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= this->getSigngrade())
        this->setSigned(true);
    else
        throw GradeTooLowException();
}
// Getters
std::string const &Form::getName(void) const
{
    return(_name);
}

bool Form::getSigned(void) const
{
    return (_signed);
}
int Form::getSigngrade(void) const
{
    return (_signgrade);
}
int Form::getExecgrade(void) const
{
    return (_execgrade);
}

// Setters
void Form::setSigned(bool status)
{
    this->_signed = status;
}

std::ostream& operator<<(std::ostream& out, const Form &form)
{
    out << "The form " << form.getName() << " needs a bureaucrat of grade " << form.getSigngrade() <<
        " to be signed and a bureaucrat of grade "<< form.getExecgrade() << " to be executed" << std::endl;
    if(form.getSigned())
        out << "This form has already been signed" << std::endl;
    else
        out << "This form is not signed" << std::endl;
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

