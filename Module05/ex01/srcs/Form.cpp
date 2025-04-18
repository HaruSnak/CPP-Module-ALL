/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:07:02 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 11:01:21 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Form::Form(std::string name, int gradeToSign, int gradeToExec): m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExec(gradeToExec)
{
	std::cout << "Form constructor called ~ " << this->m_name << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Form::Form(const Form &copy) : m_name(copy.m_name), m_isSigned(copy.m_isSigned), m_gradeToSign(copy.m_gradeToSign), m_gradeToExec(copy.m_gradeToExec)
{
	std::cout << "Form constructor copy ~ " << this->m_name << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Form::~Form()
{
	std::cout << "Form destructor called ~ " << this->m_name << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Form& Form::operator=(Form& copy)
{
	if (this != &copy)
	{
		this->m_isSigned = copy.m_isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &src)
{
	std::cout << src.getName() << ", status: " << (src.getIsSigned() ? "signed" : "unsigned")
	<< ", requires grade " << src.getGradeToSign() << " to sign, grade " << src.getGradeToExec() << " to execute." << std::endl;
	return (os);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	Form::beSigned(const Bureaucrat &bureauCrat)
{
	if (this->m_isSigned)
	{
		std::cout << bureauCrat.getName() << " couldn't sign " << this->getName() << " because Form is already signed" << std::endl;
		return ;
	}
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

const std::string	Form::getName(void) const
{
	return (m_name);
}

bool Form::getIsSigned(void) const
{
	return (m_isSigned);
}

int Form::getGradeToSign(void) const
{
	return (m_gradeToSign);
}

int Form::getGradeToExec(void) const
{
	return (m_gradeToExec);
}
