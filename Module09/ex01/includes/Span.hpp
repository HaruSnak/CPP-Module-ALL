/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:32:36 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/28 16:55:20 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <limits>
# include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> vec;
	public:
		Span(unsigned int maxNbr);
		Span(const Span &copy);
		~Span();
		Span& operator=(const Span& copy);
		void	addNumber(unsigned int number);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif
