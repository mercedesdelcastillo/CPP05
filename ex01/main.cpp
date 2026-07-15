#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	
	try
	{
		Bureaucrat worker("Andy", 40);
		Form	form("Rules", 160, 40);

		std::cout << worker;
		std::cout << form;
		worker.signForm(&form);
		std::cout << form;
	}		
	catch(Form::GradeTooHighException e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Form::GradeTooLowException e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout <<"\n------------\n\n";
	try
	{
		Bureaucrat worker("Andy", 40);
		Form	form("Rules", 50, 40);

		std::cout << worker;
		std::cout << form;
		worker.signForm(&form);
		std::cout << form;
	}		
	catch(Form::GradeTooHighException e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Form::GradeTooLowException e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout <<"\n------------\n\n";
	try
	{
		Bureaucrat worker("Andy", 40);
		Form	*form = new Form("Rules", 50, 40);

		std::cout << worker;
		std::cout << *form;
		worker.signForm(form);
		std::cout << *form;
		delete form;
	}		
	catch(Form::GradeTooHighException e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Form::GradeTooLowException e)
    {
        std::cerr << e.what() << '\n';
    }

	return 0;
}
