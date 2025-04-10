#include "../includes/Bureaucrat.hpp"

// Throw hors try/catch = std::terminate() qui tente de fermer l'exception donc erreur.
int	main(void)
{
	Bureaucrat joe("Joe", 150);

	std::cout << std::endl << "\033[35mGrade: \033[31m" << joe.getGrade() << "\033[35m | Name: \033[31m" << joe.getName() + "\033[00m" << std::endl;
	std::cout << joe << std::endl;
	try
	{
		joe.incrementGrade();
		std::cout << joe << std::endl;
		Bureaucrat steven("Steven", 150);
		steven.decrementGrade();
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