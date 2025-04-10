#ifndef GradeTooLowException_HPP
# define GradeTooLowException_HPP

# include <iostream>
# include <string>

class GradeTooLowException : public std::exception
{
	public:
		virtual const char* what(void) const throw() {
			return ("Grade is too low!");
		}
};

#endif
