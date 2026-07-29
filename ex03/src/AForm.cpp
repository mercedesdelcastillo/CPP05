/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:32:03 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 10:09:24 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Constructors
AForm::AForm(void) : _name("Default"), _target("Default target"), _signed(false), _signgrade(150), _execgrade(150)
{
    std::cout << "A new Default Aform was created" << std::endl;
}

AForm::AForm(std::string name, std::string target, int signgrade, int execgrade) : _name(name), _target(target), _signgrade(signgrade), _execgrade(execgrade)
{
    this->_signed = false;
    std::cout << "A concrete form was created" << std::endl;
    return;
}

AForm::AForm(const AForm &other) : _name(other._name), _target(other._target), _signed(other._signed), _signgrade(other._signgrade), _execgrade(other._execgrade)
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
        this->_target = other._target;
    }
    return (*this);
}

// Public Methods
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= this->getSigngrade())
        this->setSigned(true);
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
    if(!this->getSigned())
        throw NotSignedExpeption();
    if(executor.getGrade() > this->getExecgrade())
        throw BuroGradeTooLowException();
    this->action();
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
std::string const &AForm::getTarget(void) const
{
    return(_target);
}
// Setters
void AForm::setSigned(bool state)
{
    this->_signed = state;
}
void AForm::setTarget(std::string target)
{
    this->_target = target;
}

std::ostream& operator<<(std::ostream& out, const AForm &form)
{
    out << "The form " << form.getName() << " needs a bureaucrat of grade " << form.getSigngrade() <<
        " to be signed and a bureaucrat of grade "<< form.getExecgrade() << " to be executed" << std::endl;
    out << "The target of this form is " << form.getTarget() << std::endl;
    if(form.getSigned())
        out << "This form has already been signed" << std::endl;
    else
        out << "This form is not signed" << std::endl;
    return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Exception! Grade too high!");
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Exception! Grade too low!");
}

const char *AForm::NotSignedExpeption::what() const throw()
{
    return ("Exception! This form is not signed! Cannot be executed");
}
const char *AForm::BuroGradeTooLowException::what() const throw()
{
    return ("Exception! This bureaucrat grade is too low to execute this form");
}
