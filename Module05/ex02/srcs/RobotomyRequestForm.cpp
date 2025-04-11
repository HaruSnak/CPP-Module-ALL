#include "../includes/RobotomyRequestForm.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), m_target(target)
{
	std::cout << "\033[1;35mDefault constructor called ~ RobotomyRequestForm " << this->m_target + "COLOR_RED + " << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), m_target(copy.m_target)
{
	std::cout << "\033[1;35mName constructor called ~ RobotomyRequestForm " << copy.m_target + "COLOR_RED + " << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[1;31mDestructor called ~ RobotomyRequestForm " << this->m_target + "COLOR_RED + " << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->m_target = copy.m_target;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned())
	{
		std::cout << COLOR_RED + "*Drill sounds*COLOR_RED + " << std::endl;
		std::cout << "(" + executor.getName() + ")" << this->m_target << " has been robotomized successfully 50% of the time" << std::endl;
	}
	else
	{
		std::cout << this->m_target << " Failed: Failed Robotomy." << std::endl;
	}
}

