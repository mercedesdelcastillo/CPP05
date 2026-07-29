/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:30:41 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 09:47:47 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
    //Constructors
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);

    //Destructors
        ~RobotomyRequestForm();

    //Overload Operators
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    
    //Public Methods
        void action() const;
    //Setters

    //Getters
    
    private:
        std::string _target;        
};

#endif

