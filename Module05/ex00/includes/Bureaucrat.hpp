#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat
{
	protected:
		const std::string m_name;
		int m_grade;
		GradeTooHighException GradeTooHighExceptionn;
		GradeTooLowException GradeTooLowExceptionn;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& copy);
		void	incrementGrade(void);
		void	decrementGrade(void);
		const std::string&	getName(void) const;
		int	getGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif
