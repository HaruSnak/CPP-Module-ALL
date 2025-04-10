#include "../includes/Bureaucrat.hpp"

// Throw hors try/catch = std::terminate() qui tente de fermer l'exception donc erreur.
int	main(void)
{
	Bureaucrat joe("Joe", 4);
	Form form42A("42A", 5, 10);
	Form form42B("42B", 2, 100);

	std::cout << std::endl << "\033[35mGrade: \033[31m" << joe.getGrade() << "\033[35m | Name: \033[31m" << joe.getName() + "\033[00m" << std::endl;
	std::cout << joe << std::endl;
	joe.signForm(form42A);
	if (form42A.getIsSigned())
		std::cout << "Signed !" << std::endl;
	else
		std::cout << "No Sign" << std::endl;
	std::cout << form42A << std::endl;
	try
	{
		joe.signForm(form42B);
		form42A.getIsSigned();
	}
	catch (const GradeTooHighException &e)
	{
		std::cerr << "\033[31mERROR: " << e.what() << "\033[00m" << std::endl;
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << "\033[31mERROR: " << e.what() << "\033[00m" << std::endl;
	}
	return (0);
}