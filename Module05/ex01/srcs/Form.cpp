#include "../includes/Form.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Form::Form(std::string name, int gradeToSign, int gradeToExec): m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExec(gradeToExec)
{
	std::cout << "Default constructor called ~ Form" << std::endl;
	return ;
}

Form::Form(const Form &copy) : m_name(copy.m_name), m_isSigned(copy.m_isSigned), m_gradeToSign(copy.m_gradeToSign), m_gradeToExec(copy.m_gradeToExec)
{
	std::cout << "Name constructor called ~ Form" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Form::~Form()
{
	std::cout << "Destructor called ~ Form" << std::endl;
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
	//Tax Form 42A, status: unsigned, requires grade 5 to sign, grade 10 to execute.
	std::cout << src.getName() << ", status: " << (src.getIsSigned() ? "signed" : "unsigned")
	<< ", requires grade " << src.getGradeToSign() << " to sign, grade " << src.getGradeToExec() << " to execute." << std::endl;
	return (os);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	Form::beSigned(const Bureaucrat &bureauCrat)
{
	if (bureauCrat.getGrade() < this->m_gradeToSign)
	{
		//signed the form because his grade is 10 and the grade on the form is 6
		this->m_isSigned = true;
		std::cout << bureauCrat.getName() << " signed the form " << this->getName() << " because his grade is " << bureauCrat.getGrade() << " and the grade on the form is " << this->m_gradeToSign << std::endl;
	}
	else
	{
		std::cout << bureauCrat.getName() << " couldn’t sign the form " << this->getName() << " because his grade is " << bureauCrat.getGrade() << " and the grade on the form is " << this->m_gradeToSign << std::endl;
		throw GradeTooLowExceptionn;
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
