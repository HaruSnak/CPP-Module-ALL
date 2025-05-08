/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:24:34 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/05 22:03:29 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>
# include "polishNotation.hpp"

class RPN
{
	private:
		std::stack<int> stack;
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN& operator=(const RPN& copy);
		int ResultRPN(char *argv);
};

#endif
