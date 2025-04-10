#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string m_name;
		bool m_isSigned;
		const int m_gradeToSign;
		const int m_gradeToExec;
		GradeTooHighException GradeTooHighExceptionn;
		GradeTooLowException GradeTooLowExceptionn;
	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &copy);
		~Form();
		Form& operator=(Form& copy);
		const std::string	getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		void	beSigned(const Bureaucrat &bureauCrat);
};

std::ostream &operator<<(std::ostream &os, const Form &src);

#endif
