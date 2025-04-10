#ifndef Intern_HPP
# define Intern_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

enum	formType {
	PRESIDENTIAL,
	ROBOTOMY,
	SHRUBBERY,
	UNKNOWN
};

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern& operator=(Intern& copy);
		AForm*	makeForm(const std::string& src, const std::string& target);
};

formType getFormType(const std::string& src);

#endif
