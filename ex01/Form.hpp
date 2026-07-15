#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdbool.h>
#include "Bureaucrat.hpp"

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
        bool beSigned(Bureaucrat &bureaucrat);
    
    //Setters
        void setSigned(bool state);

    //Getters
        std::string getName(void) const;
        bool getSigned(void) const;
        int getSigngrade(void) const;
        int getExecgrade(void) const;


    private:
        std::string const _name;
        bool _signed;
        int const _signgrade;
        int const _execgrade;
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

std::ostream& operator<<(std::ostream& out, const Form &form);

#endif

