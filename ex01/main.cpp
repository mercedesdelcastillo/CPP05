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
}