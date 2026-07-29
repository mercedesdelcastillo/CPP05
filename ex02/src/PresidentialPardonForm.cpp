/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:31:13 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 09:31:13 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//Constructors
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default target")
{
    std::cout << "A Presidential Default Form was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
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
        this->_target = other._target;
    }
    return (*this);
}

// Public Methods
void PresidentialPardonForm::action() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    return;
}

// Getters

// Setters





