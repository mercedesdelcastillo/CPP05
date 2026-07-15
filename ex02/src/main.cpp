#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	
	try
	{
		Bureaucrat worker("Andy", 40);
		ShrubberyCreationForm	form("Rules", 140, 40);

		std::cout << worker;
		std::cout << form;
		worker.signForm(&form);
		std::cout << form;
	}		
	catch(AForm::GradeTooHighException e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(AForm::GradeTooLowException e)
    {
        std::cerr << e.what() << '\n';
    }
	return 0;
}
