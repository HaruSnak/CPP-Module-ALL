/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:49:30 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/21 12:35:20 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
typename T::const_iterator	easyfind(const T& container, int number)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == number)
			return (it);
	}
	throw std::runtime_error("Error");
	return (container.end());
}
