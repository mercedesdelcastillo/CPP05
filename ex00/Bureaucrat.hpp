#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

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
        Bureaucrat &operator=(const Bureaucrat &other) = delete;
    
    //Public Methods
		void incrementGrade(int increment);
		void decrementGrade(int decrement);
    //Setters
		void setGrade(int grade);
    //Getters
		std::string getName(void) const;
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
