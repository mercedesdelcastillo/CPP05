/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medel-ca <medel-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:29:56 by medel-ca          #+#    #+#             */
/*   Updated: 2026/07/29 09:29:56 by medel-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat worker("Andy", 40);


	std::cout << worker;
	worker.incrementGrade(20);
	worker.incrementGrade(20);
	worker.incrementGrade(20);

	std::cout <<"\n------------\n\n";
	Bureaucrat worker_def;
	std::cout << worker_def;
	worker_def.decrementGrade(2);

	std::cout <<"\n------------\n\n";
	Bureaucrat worker_cpy(worker);
	std::cout << worker_cpy;

	std::cout <<"\n------------\n\n";
	worker_def = worker;
	std::cout << worker;
	std::cout << worker_def;
}