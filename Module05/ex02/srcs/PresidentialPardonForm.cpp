#include "../includes/PresidentialPardonForm.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), m_target(target)
{
	std::cout << "\033[1;35mDefault constructor called ~ ShrubberyCreationForm " << this->m_target + "\033[0m" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) , m_target(copy.m_target)
{
	std::cout << "\033[1;35mName constructor called ~ ShrubberyCreationForm " << copy.m_target + "\033[0m" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[1;31mDestructor called ~ ShrubberyCreationForm " << this->m_target + "\033[0m" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->m_target = copy.m_target;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned())
	{
		std::cout << "(" + executor.getName() + ")" << this->m_target << " was pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

