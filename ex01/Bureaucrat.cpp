#include "Bureaucrat.hpp"

//Constructors
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "Parametric constructor called" << std::endl;
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructor called" << std::endl;
}
// Destructors
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor called" << std::endl;
}

// Overload Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if(this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

// Public Methods
void Bureaucrat::incrementGrade(int increment)
{
    int oldGrade = this->getGrade();
    int newGrade = this->getGrade() - increment;
    this->setGrade(newGrade);
    if(oldGrade != this->_grade)
        std::cout << "The new grade of " << this->_name << " is " << this->_grade << std::endl;
    else
        std::cout << "The grade of " << this->_name << " still is " << this->_grade << std::endl;
    return;
}

void Bureaucrat::decrementGrade(int decrement)
{
    int oldGrade = this->getGrade();
    int newGrade = this->getGrade() + decrement;
    this->setGrade(newGrade);
    if(oldGrade != this->_grade)
        std::cout << "The new grade of " << this->_name << " is " << this->_grade << std::endl;
    else
        std::cout << "The grade of " << this->_name << " still is " << this->_grade << std::endl;
    return;
}

void Bureaucrat::signForm(Form *form)
{
    if(form->beSigned(this))
        std::cout << this->getName() << " signed " << form->getName() << std::endl;
    else
        std::cout << this->getName() << " coudn't sign " << form->getName() << " because doesn't have the apropiate grade" << std::endl;
}

// Getters
std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

// Setters
void Bureaucrat::setGrade(int grade)
{
    try
    {
        if(grade < 1)
            throw GradeTooHighException();
        else if(grade > 150)
            throw GradeTooLowException();
        else
            this->_grade = grade;
    }
    catch(GradeTooHighException e)
    {
        this->_grade = 1;
        std::cerr << e.what() << '\n';
    }
    catch(GradeTooLowException e)
    {
        this->_grade = 150;
        std::cerr << e.what() << '\n';
    }
    return;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Exception! Grade too high!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exception! Grade too low!");
}
