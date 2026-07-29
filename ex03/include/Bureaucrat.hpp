/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:31:33 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 10:03:59 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

class Bureaucrat
{
    public:
    //Constructors
        Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
    //Destructors
        ~Bureaucrat();
    //Overload Operators
        Bureaucrat &operator=(const Bureaucrat &other);    
    //Public Methods
		void incrementGrade(int increment);
		void decrementGrade(int decrement);
        void signForm(AForm *form);
        void executeForm(AForm const &form);
    //Setters
		void setGrade(int grade);
    //Getters
		std::string const &getName(void) const;
		int getGrade(void) const;
    private:
        std::string const	_name;
        int					_grade;
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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat);

#endif
