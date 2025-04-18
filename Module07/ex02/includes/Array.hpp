/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:13:38 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/18 14:13:39 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cstdlib>

template<typename T>
class Array
{
	private:
		T *m_array;
		size_t m_size;
	public:
		Array();
		Array(unsigned int number);
		Array(const Array &copy);
		~Array();
		Array& operator=(const Array& copy);
		T& operator[](signed int size);
		size_t	size(void) const;
};

#endif
