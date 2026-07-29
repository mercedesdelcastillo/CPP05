/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:31:43 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 10:03:55 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"

class Intern
{
    public:
    //Constructors
        Intern(void);
        Intern(const Intern& other);
    //Destructors
        ~Intern();
    //Overload Operators
        Intern &operator=(const Intern &other);    
    //Public Methods
        AForm *makeForm(std::string name, std::string target);    
    //Setters
    //Getters       
};

#endif

