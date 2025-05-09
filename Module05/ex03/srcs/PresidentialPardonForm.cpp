/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:10:02 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/09 21:10:03 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), m_target(target)
{
	std::cout << "Default constructor called ~ ShrubberyCreationForm " << this->m_target << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) , m_target(copy.m_target)
{
	std::cout << "Name constructor called ~ ShrubberyCreationForm " << copy.m_target << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called ~ ShrubberyCreationForm " << this->m_target << std::endl;
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

