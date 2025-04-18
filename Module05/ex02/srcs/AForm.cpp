/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:13:24 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 12:14:35 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExec(gradeToExec)
{
	std::cout << "Default constructor called ~ Form " << this->m_name << std::endl;
	if (this->m_name.empty())
	{
		std::cerr << "Error: Invalid constructor, please enter a correct name!" << std::endl;
		exit(-1);
	}
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

AForm::AForm(const AForm &copy) : m_name(copy.m_name), m_isSigned(copy.m_isSigned), m_gradeToSign(copy.m_gradeToSign), m_gradeToExec(copy.m_gradeToExec)
{
	std::cout << "Name constructor called ~ Form " << this->m_name << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

AForm::~AForm()
{
	std::cout << "Destructor called ~ Form " << this->m_name << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

AForm& AForm::operator=(AForm& copy)
{
	if (this != &copy)
	{
		this->m_isSigned = copy.m_isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &src)
{
	std::cout << src.getName() << ", status: " << (src.getIsSigned() ? "signed" : "unsigned")
	<< ", requires grade " << src.getGradeToSign() << " to sign, grade " << src.getGradeToExec() << " to execute." << std::endl;
	return (os);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	AForm::beSigned(const Bureaucrat &bureauCrat)
{
	if (bureauCrat.getGrade() <= this->m_gradeToSign)
	{
		this->m_isSigned = true;
		std::cout << bureauCrat.getName() << " signed the form " << this->getName() << " because his grade is " << bureauCrat.getGrade() << " and the grade on the form is " << this->m_gradeToSign << std::endl;
	}
	else
	{
		throw Bureaucrat::GradeTooLowException();
	}
	return ;
}

const std::string	AForm::getName(void) const
{
	return (m_name);
}

bool AForm::getIsSigned(void) const
{
	return (m_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (m_gradeToSign);
}

int AForm::getGradeToExec(void) const
{
	return (m_gradeToExec);
}
