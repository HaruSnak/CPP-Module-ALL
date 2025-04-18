/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:04:16 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 10:43:06 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string m_name;
		bool m_isSigned;
		const int m_gradeToSign;
		const int m_gradeToExec;
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
