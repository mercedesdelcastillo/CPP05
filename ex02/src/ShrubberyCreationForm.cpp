#include "ShrubberyCreationForm.hpp"

//Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
    std::cout << "Shrubery Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int signgrade, int execgrade) : AForm(name, signgrade, execgrade)
{
    if(signgrade < 1 || execgrade < 1)
            throw GradeTooHighException();
    else if(signgrade > 146 || execgrade > 137)
        throw GradeTooLowException();
    create_file(name);
    std::cout << "Shrubbery Atributes constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    std::cout << "Shrubbery Copy constructor called" << std::endl;
    (void) other;
}
// Destructors
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery Destructor called" << std::endl;
}

// Overload Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "Shrubbery Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Public Methods
void    ShrubberyCreationForm::create_file(std::string name)
{
    
}

// Getters

// Setters



