/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:51:54 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 10:38:34 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Bureaucrat
{
	protected:
		const std::string m_name;
		int m_grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Grade is too high!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Grade is too low!");
				}
		};
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
