#include "../includes/Intern.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Intern::Intern()
{
	std::cout << "\033[1;35mDefault constructor called ~ Intern\033[0m" << std::endl;
	return ;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout << "\033[1;35mName constructor called ~ Intern\033[0m" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Intern::~Intern()
{
	std::cout << "\033[1;31mDestructor called ~ Intern\033[0m" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Intern& Intern::operator=(Intern& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

formType getFormType(const std::string& src)
{
	if (src == "presidential pardon")
		return (PRESIDENTIAL);
	if (src == "robotomy request")
		return (ROBOTOMY);
	if (src == "shrubbery creation")
		return (SHRUBBERY);
	return (UNKNOWN);
}

AForm*	Intern::makeForm(const std::string& src, const std::string& target)
{
	if (src.empty() || target.empty())
	{
		std::cerr << "Error: Name Form or Target empty!" << std::endl;
		return (NULL);
	}
	switch (getFormType(src))
	{
	case PRESIDENTIAL:
		std::cout << "Intern creates Presidential Form" << std::endl;
		return (new PresidentialPardonForm(target));
	case ROBOTOMY:
		std::cout << "Intern creates Robotomy Form" << std::endl;
		return (new RobotomyRequestForm(target));
	case SHRUBBERY:
		std::cout << "Intern creates Shrubbery Form" << std::endl;
		return (new ShrubberyCreationForm(target));
	default:
		std::cout << "Error: Unknown form name" << std::endl;
		return (NULL);
	}
}

