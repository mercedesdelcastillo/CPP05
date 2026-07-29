/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:30:48 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 09:50:48 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
    public:
    //Constructors
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);

    //Destructors
        ~ShrubberyCreationForm();

    //Overload Operators
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    
    //Public Methods
        void action() const;
    //Setters

    //Getters
    
    private:
        std::string _target;        
};

#endif

