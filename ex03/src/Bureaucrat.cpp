#include "Bureaucrat.hpp"

//Constructors
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
    std::cout << "A Default Bureaucrat was born" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "A specific Bureaucrat was born" << std::endl;
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "A Bureaucrat was copied" << std::endl;
}
// Destructors
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat retired" << std::endl;
}

// Overload Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Not the best idea, you know have to nearly equals bureaucrats" << std::endl;
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

void Bureaucrat::signForm(AForm *form)
{
    try
    {
        form->beSigned(*this);
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    std::cout << this->getName() << " signed " << form->getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
// Getters
std::string const &Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
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
    catch(GradeTooHighException &e)
    {
        this->_grade = 1;
        std::cerr << e.what() << '\n';
    }
    catch(GradeTooLowException &e)
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
