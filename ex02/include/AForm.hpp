/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:30:26 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 09:30:26 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <stdbool.h>

class Bureaucrat;

class AForm
{
    public:
    //Constructors
        AForm(void);
        AForm(const AForm& other);
        AForm(std::string name, int signgrade, int execgrade);

    //Destructors
        virtual ~AForm();

    //Overload Operators
        AForm &operator=(const AForm &other);
    
    //Public Methods
        virtual void beSigned(Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;
    
    //Setters
        void setSigned(bool state);
        

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

        class      NotSignedExpeption : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class      BuroGradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };


    private:
        std::string const _name;
        bool _signed;
        int const _signgrade;
        int const _execgrade;
        
        virtual void action() const = 0;

};

std::ostream& operator<<(std::ostream& out, const AForm &form);

#endif

