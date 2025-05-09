/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:01 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/09 21:00:37 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "Error: Only numbers as arguments!" << std::endl;
		return (-1);
	}
	PmergeMe johnson(argv);
	johnson.printSort();
    return (0);
}