/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:12:06 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/18 14:12:07 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include <cstddef>

template<typename T>
void	iter(T* table, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
	{
		f(table[i]);
	}
}

#endif
