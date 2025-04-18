/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:29:57 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 16:29:58 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template<typename T>
void	swap(T& a, T& b)
{
	T temp = b;
	b = a;
	a = temp;
	return ;
}

template<typename T>
T	min(T& a, T& b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

template<typename T>
T	max(T& a, T& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
