/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:30:37 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 09:47:43 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
    //Constructors
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);

    //Destructors
        ~PresidentialPardonForm();

    //Overload Operators
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    
    //Public Methods
    void action() const;
    //Setters

    //Getters
    
    private:
        std::string _target;
};

#endif

