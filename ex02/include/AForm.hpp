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
        AForm(std::string name, int signgrade, int execgrade);
        AForm(const AForm& other);

    //Destructors
        virtual ~AForm();

    //Overload Operators
        AForm &operator=(const AForm &other);
    
    //Public Methods
        virtual bool beSigned(Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor, std::string target);
        virtual void action(std::string target) = 0;
    
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


    private:
        std::string const _name;
        bool _signed;
        int const _signgrade;
        int const _execgrade;
        
};

std::ostream& operator<<(std::ostream& out, const AForm &form);

#endif

