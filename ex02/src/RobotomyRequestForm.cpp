/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:31:17 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 10:54:26 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

//Constructors
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default target")
{
    std::cout << "A Robotomy Default Form was created" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Robotomy with Atributes Form was created" << std::endl;
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
        this->_target = other._target;
    }
    return (*this);
}


// Public Methods
void RobotomyRequestForm::action() const
{
    int chance = rand() % 2;
    if(chance == 1)
    {
        std::cout << ">>>DrilliNg NoiSEssSseESsSSsS<<<" << std::endl;
        std::cout << this->_target << " has been robotomized" << std::endl;
    }
    else
        std::cout << "Best luck next time robotomizing!" << std::endl;
    return;
}

// Getters

// Setters



