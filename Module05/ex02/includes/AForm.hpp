#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat;
class GradeTooLowException;

class AForm
{
	private:
		const std::string m_name;
		bool m_isSigned;
		const int m_gradeToSign;
		const int m_gradeToExec;
	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &copy);
		~AForm();
		AForm& operator=(AForm& copy);
		const std::string	getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		void	beSigned(const Bureaucrat &bureauCrat);
		virtual void execute(const Bureaucrat &bureauCrat) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &src);

#endif
