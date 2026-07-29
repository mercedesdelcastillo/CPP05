/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:30:16 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 09:30:16 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdbool.h>

class Bureaucrat;

class Form
{
    public:
    //Constructors
        Form(void);
        Form(std::string name, int signgrade, int execgrade);
        Form(const Form& other);

    //Destructors
        ~Form();

    //Overload Operators
        Form &operator=(const Form &other);
    
    //Public Methods
        void beSigned(Bureaucrat &bureaucrat);
    
    //Setters
        void setSigned(bool status);

    //Getters
        std::string const &getName(void) const;
        bool getSigned(void) const;
        int getSigngrade(void) const;
        int getExecgrade(void) const;

        class      GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class      GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };


    private:
        std::string const _name;
        bool _signed;
        int const _signgrade;
        int const _execgrade;
        
};

std::ostream& operator<<(std::ostream& out, const Form &form);

#endif

