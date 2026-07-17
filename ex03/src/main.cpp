#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *form;
	Bureaucrat worker("Jon", 1);
	form = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	worker.signForm(form);
	std::cout << *form;
	form->execute(worker);
	worker.executeForm(*form);
	delete form;
	return 0;
}
