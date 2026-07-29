/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:31:09 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 10:58:20 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int main()
{
	//AForm form;
	//AForm *form = new RobotomyRequestForm();
	srand((unsigned)time(0));
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
			form.execute(worker);
			form.execute(worker);
			form.execute(worker);
			form.execute(worker);
			form.execute(worker);
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

	std::cout <<"\n------------\n\n";
	try
	{
		Bureaucrat worker("Andy", 40);
		ShrubberyCreationForm	form("Garden");
		std::cout << worker;
		std::cout << form;
		try
		{
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

	std::cout <<"\n------------\n\n";
	try
	{
		Bureaucrat worker("Andy", 10);
		PresidentialPardonForm	form("Mike");
		std::cout << worker;
		std::cout << form;
		try
		{
			worker.signForm(&form);
			form.execute(worker);
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
    }
	return 0;
}
