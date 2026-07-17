#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

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

