/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:32:14 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 10:11:52 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

//Constructors
Intern::Intern(void)
{
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    (void) other;
}
// Destructors
Intern::~Intern(void)
{
    std::cout << "Intern Destructor called" << std::endl;
}

// Overload Operators
Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern Assignment operator called" << std::endl;
    (void)other;
    return (*this);
}

// Public Methods
AForm *makeRobot(std::string target)
{
    AForm *form = new RobotomyRequestForm(target);
    return form;
}

AForm *makeShrubbery(std::string target)
{
    AForm *form = new ShrubberyCreationForm(target);
    return form;
}

AForm *makePresident(std::string target)
{
    AForm *form = new PresidentialPardonForm(target);
    return form;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    if(name.empty() || target.empty())
        return NULL;
    std::string type_forms[] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};
    AForm *(*all_forms[])(std::string target) = {makeRobot, makeShrubbery, makePresident};
    AForm *ret = NULL;
    for (int i = 0; i < 3; i++)
	{
		if (name == type_forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			ret = all_forms[i](target);
		}
    }
    if(ret == NULL)
    {
        std::cout << "Intern cannot create a form called " << name << std::endl;	
    }
	return (ret);
}
