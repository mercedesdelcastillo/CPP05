#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		Bureaucrat worker("Jon", 1);
		AForm *form = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		worker.signForm(form);
		std::cout << *form;
		form->execute(worker);
		worker.executeForm(*form);
		delete form;
	}

	std::cout <<"\n------------\n\n";
	{
		Intern someRandomIntern;
		AForm *form2;
		Bureaucrat worker("Jon", 1);
		form2 = someRandomIntern.makeForm("ShrubberyCreationForm", "Garden");
		worker.signForm(form2);
		std::cout << *form2;
		form2->execute(worker);
		worker.executeForm(*form2);
		delete form2;
	}
	std::cout <<"\n------------\n\n";
	{
		Intern someRandomIntern;
		AForm *form1;
		Bureaucrat worker("Jon", 1);
		form1 = someRandomIntern.makeForm("PresidentialPardonForm", "Friend");
		worker.signForm(form1);
		std::cout << *form1;
		form1->execute(worker);
		worker.executeForm(*form1);
		delete form1;
	}
	std::cout <<"\n------------\n\n";
	{
		Intern someRandomIntern;
		AForm *form;
		Bureaucrat worker("Jon", 1);
		form = someRandomIntern.makeForm("OtherForm", "Friend");
		if(form)
			std::cout << *form;
	}
	return 0;


}
