#ifndef GradeTooHighException_HPP
# define GradeTooHighException_HPP

# include <iostream>
# include <string>

class GradeTooHighException : public std::exception
{
	public:
		virtual const char* what(void) const throw() {
			return ("Grade is too high!");
		}
};

#endif
