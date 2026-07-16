#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat worker("Andy", 40);
		RobotomyRequestForm	form("\'Robotize\'", 70, 40);

		std::cout << worker;
		std::cout << form;
		form.execute(worker, "Enemy");
		worker.signForm(&form);
		form.execute(worker, "Enemy");
	}		
	catch(AForm::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout <<"\n------------\n\n";
	try
	{
		Bureaucrat worker("Andy", 40);
		ShrubberyCreationForm	form("\'Plant a tree\'", 140, 40);

		std::cout << worker;
		std::cout << form;
		form.execute(worker, "Garden");
		worker.signForm(&form);
		form.execute(worker, "Garden");
	}		
	catch(AForm::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout <<"\n------------\n\n";
	try
	{
		Bureaucrat worker("Andy", 10);
		PresidentialPardonForm	form("\'Indulto\'", 25, 5);

		std::cout << worker;
		std::cout << form;
		form.execute(worker, "Friend");
		worker.signForm(&form);
		form.execute(worker, "Friend");
		std::cout << form;
	}		
	catch(AForm::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
	return 0;
}
