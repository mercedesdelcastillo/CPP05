/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:30:07 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 09:45:04 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

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
        void signForm(Form *form);
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
