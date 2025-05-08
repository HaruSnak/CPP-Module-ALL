/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:30:20 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/05 14:44:33 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

bool isFloat(float nombre)
{
    float partieEntiere;
    float partieDecimale = std::modf(nombre, &partieEntiere);
    return (partieDecimale != 0.0f);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Only one argument is valid, it must be a file containing a Database!" << std::endl;
		return (-1);
	}
	BitcoinExchange btcExchange;
	btcExchange.searchInDB(argv[1]);
    return (0);
}