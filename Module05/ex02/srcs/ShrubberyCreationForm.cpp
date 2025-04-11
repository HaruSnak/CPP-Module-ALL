#include "../includes/ShrubberyCreationForm.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), m_target(target)
{
	std::cout << "\033[1;35mDefault constructor called ~ ShrubberyCreationForm " << this->m_target + "COLOR_RED + " << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), m_target(copy.m_target)
{
	std::cout << "\033[1;35mName constructor called ~ ShrubberyCreationForm " << copy.m_target + "COLOR_RED + " << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[1;31mDestructor called ~ ShrubberyCreationForm " << this->m_target + "COLOR_RED + " << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->m_target = copy.m_target;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	(void)executor;
	std::ofstream file((m_target + "_shrubbery").c_str());
    file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\";
}

