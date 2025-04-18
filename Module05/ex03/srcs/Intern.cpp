/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:34 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Intern::Intern()
{
	std::cout << "Default constructor called ~ Intern" << std::endl;
	return ;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout << "Name constructor called ~ Intern" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Intern::~Intern()
{
	std::cout << "Destructor called ~ Intern" << std::endl;
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

