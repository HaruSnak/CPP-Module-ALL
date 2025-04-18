/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:19:22 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 14:19:34 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

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
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern& operator=(Intern& copy);
		AForm*	makeForm(const std::string& src, const std::string& target);
};

formType getFormType(const std::string& src);

#endif
