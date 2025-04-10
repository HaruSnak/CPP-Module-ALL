/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:38:57 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/09 12:20:24 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1 || N > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: The zombie horde's size is out of range!" << std::endl;
		return (NULL);
	}
	if (name.empty())
	{	
		std::cerr << "Error: Zombie Horde has an empty name!" << std::endl;
		return (NULL);
	}
	Zombie *zombie = new Zombie[N];
	if (!zombie)
		return (NULL);
	for (int i = 0; i < N; i++)
	{
		new (&zombie[i]) Zombie(name);
		if (!&zombie[i])
			return (NULL);
	}
	return (zombie);
}
