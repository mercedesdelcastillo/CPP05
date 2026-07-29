/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:31:28 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 10:02:37 by medel-ca         ###   ########.fr       */
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
        AForm(std::string name, std::string target, int signgrade, int execgrade);
        AForm(const AForm& other);
    //Destructors
        virtual ~AForm();
    //Overload Operators
        AForm &operator=(const AForm &other);
    //Public Methods
        virtual void beSigned(Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;
        virtual void action() const = 0;
    //Setters
        void setSigned(bool state);
        void setTarget(std::string target);
    //Getters
        std::string const &getName(void) const;
        bool getSigned(void) const;
        int getSigngrade(void) const;
        int getExecgrade(void) const;
        std::string const &getTarget(void) const;
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
        std::string _target;
        bool _signed;
        int const _signgrade;
        int const _execgrade;       
};

std::ostream& operator<<(std::ostream& out, const AForm &form);

#endif

