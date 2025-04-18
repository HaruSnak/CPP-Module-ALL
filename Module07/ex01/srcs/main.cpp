/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:12:41 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/18 14:12:57 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

template <typename T>
void printElement(T& elem)
{
    std::cout << elem << std::endl;
}

template <typename T>
void increment(T& value)
{
	++value;
}

int main(void)
{
    std::cout << "=== Test with an array of integer ===" << std::endl;
    int tabInt[] = {1, 2, 3, 4, 5};
    iter(tabInt, 5, printElement);
	std::cout << "-------------------------------------------------" << std::endl;
    iter(tabInt, 5, increment);
	std::cout << "-------------------------------------------------" << std::endl;
    iter(tabInt, 5, printElement);

    std::cout << "\n=== Test with an array of doubles ===" << std::endl;
    double tabDouble[] = {1.1, 2.2, 3.3};
    iter(tabDouble, 3, printElement);

    std::cout << "\n=== Test with an array of strings ===" << std::endl;
    std::string tabStr[] = {"Hello", "World", "!"};
    iter(tabStr, 3, printElement);
    return (0);
}