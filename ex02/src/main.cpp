#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	//AForm form;
	//AForm *form = new RobotomyRequestForm();
	//RobotomyRequestForm bad;
	//std::cout << bad;
	try
	{
		Bureaucrat worker("Andy", 45);
		RobotomyRequestForm	form("Ben");

		std::cout << worker;
		std::cout << form;
		try
		{
		//	form.execute(worker, "Enemy");
			worker.signForm(&form);
			form.execute(worker);
			worker.executeForm(form);
		}
		catch(AForm::NotSignedExpeption& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(AForm::BuroGradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}		
	catch(AForm::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }

/*	std::cout <<"\n------------\n\n";
	try
	{
		Bureaucrat worker("Andy", 40);
		ShrubberyCreationForm	form("\'Plant a tree\'", 140, 40);
		std::cout << worker;
		std::cout << form;
		try
		{
			worker.signForm(&form);
			form.execute(worker, "Garden");
			worker.executeForm(form, "Medow");
		}
		catch(AForm::NotSignedExpeption& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(AForm::BuroGradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
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
		try
		{
			worker.signForm(&form);
			form.execute(worker, "Friend");
			std::cout << form;
		}
		catch(AForm::NotSignedExpeption& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(AForm::BuroGradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}		
	catch(AForm::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }*/
	return 0;
}
