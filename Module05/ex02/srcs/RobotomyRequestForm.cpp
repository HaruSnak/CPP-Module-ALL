/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:13:37 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), m_target(target)
{
	std::cout << "Default constructor called ~ RobotomyRequestForm " << this->m_target << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), m_target(copy.m_target)
{
	std::cout << "Name constructor called ~ RobotomyRequestForm " << copy.m_target << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called ~ RobotomyRequestForm " << this->m_target << std::endl;
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
		std::cout << "*Drill sounds*" << std::endl;
		std::cout << "(" + executor.getName() + ")" << this->m_target << " has been robotomized successfully 50% of the time" << std::endl;
	}
	else
	{
		std::cout << this->m_target << " Failed: Failed Robotomy." << std::endl;
	}
}

