#include "../includes/Bureaucrat.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name), m_grade(grade)
{
	std::cout << "\033[1;35mDefault constructor called ~ Bureaucrat " << this->m_name + "\033[0m" << std::endl;
	if (this->m_name.empty())
	{
		std::cerr << "Error: Invalid constructor, please enter a correct name!" << std::endl;
		exit(-1);
	}
	if (grade < 0)
		throw Bureaucrat::GradeTooHighExceptionn;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowExceptionn;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): m_name(copy.m_name), m_grade(copy.m_grade)
{
	std::cout << "\033[1;35mName constructor called ~ Bureaucrat " << this->m_name + "\033[0m" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[1;31mDestructor called ~ Bureaucrat " << this->m_name + "\033[0m" << std::endl;
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
	std::cout << "\033[31m" + src.getName() << "\033[35m, bureaucrat grade \033[31m" << src.getGrade() << ".\033[00m";
	return (os);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void Bureaucrat::executeForm(AForm const & form) const
{
	if (form.getIsSigned() && this->getGrade() <= form.getGradeToExec())
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
		throw Bureaucrat::GradeTooHighExceptionn;
		return ;
	}
	this->m_grade--;
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if ((this->m_grade + 1) > 150)
	{
		throw Bureaucrat::GradeTooLowExceptionn;
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
