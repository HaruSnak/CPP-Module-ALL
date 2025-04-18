/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:13:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 12:14:35 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name), m_grade(grade)
{
	std::cout << "Default constructor called ~ Bureaucrat " << this->m_name << std::endl;
	if (this->m_name.empty())
	{
		std::cerr << "Error: Invalid constructor, please enter a correct name!" << std::endl;
		exit(-1);
	}
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): m_name(copy.m_name), m_grade(copy.m_grade)
{
	std::cout << "Name constructor called ~ Bureaucrat " << this->m_name << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called ~ Bureaucrat " << this->m_name << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		this->m_grade = copy.m_grade;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
	std::cout << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";	return (os);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void Bureaucrat::executeForm(AForm const & form) const
{
	if (form.getIsSigned() && this->getGrade() < form.getGradeToExec())
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	else
	{
		std::ostringstream oss;
		oss << "ERROR: " << this->getName() << " has a grade of " << this->getGrade()
			<< " compared to the form " << form.getName() 
			<< " having a grade above this one which is " << form.getGradeToExec();
		throw std::runtime_error(oss.str());
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void	Bureaucrat::incrementGrade(void)
{
	if ((this->m_grade - 1) < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->m_grade--;
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if ((this->m_grade + 1) > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		exit(-1);
	}
	this->m_grade++;
	return ;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->m_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->m_grade);
}
