/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/03/06 18:16:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*int main(void)
{
	Fixed a(10.5f);
	Fixed b(5.25f);
	Fixed c(10.5f);

	// Test des opérateurs de comparaison
	std::cout << "Comparaisons :" << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;  // Devrait afficher 1 (true)
	std::cout << "a < b : " << (a < b) << std::endl;  // Devrait afficher 0 (false)
	std::cout << "a >= c : " << (a >= c) << std::endl; // Devrait afficher 1 (true)
	std::cout << "a <= c : " << (a <= c) << std::endl; // Devrait afficher 1 (true)
	std::cout << "a == c : " << (a == c) << std::endl; // Devrait afficher 1 (true)
	std::cout << "a != b : " << (a != b) << std::endl; // Devrait afficher 1 (true)
	std::cout << std::endl;

	// Test des opérateurs arithmétiques
	std::cout << "Opérations arithmétiques :" << std::endl;
	Fixed d = a + b;
	std::cout << "a + b : " << d << std::endl; // Devra it afficher 15.75
	Fixed e = a - b;
	std::cout << "a - b : " << e << std::endl; // Devrait afficher 5.25
	Fixed f = a * b;
	std::cout << "a * b : " << f << std::endl; // Devrait afficher 55.125
	Fixed g = a / b;
	std::cout << "a / b : " << g << std::endl; // Devrait afficher 2
	std::cout << std::endl;

	// Test des opérateurs d'incrémentation et de décrémentation
	std::cout << "Incrémentation et décrémentation :" << std::endl;
	std::cout << "a avant incrémentation : " << a << std::endl; // Devrait afficher 10.5
	std::cout << "a++ : " << a++ << std::endl; // Devrait afficher 10.5 (post-incrémentation)
	std::cout << "a après a++ : " << a << std::endl; // Devrait afficher 10.5 + ε
	std::cout << "++a : " << ++a << std::endl; // Devrait afficher 10.5 + 2ε (pré-incrémentation)
	std::cout << "a après ++a : " << a << std::endl; // Devrait afficher 10.5 + 2ε
	std::cout << "b avant décrémentation : " << b << std::endl; // Devrait afficher 5.25
	std::cout << "b-- : " << b-- << std::endl; // Devrait afficher 5.25 (post-décrémentation)
	std::cout << "b après b-- : " << b << std::endl; // Devrait afficher 5.25 - ε
	std::cout << "--b : " << --b << std::endl; // Devrait afficher 5.25 - 2ε (pré-décrémentation)
	std::cout << "b après --b : " << b << std::endl; // Devrait afficher 5.25 - 2ε
	std::cout << std::endl;

	// Test des fonctions min et max
	std::cout << "Fonctions min et max :" << std::endl;
	Fixed& minRef = Fixed::min(a, b);
	std::cout << "min(a, b) : " << minRef << std::endl; // Devrait afficher 5.25 - 2ε
	const Fixed& minConstRef = Fixed::min(a, c);
	std::cout << "min(a, c) : " << minConstRef << std::endl; // Devrait afficher 10.5
	Fixed& maxRef = Fixed::max(a, b);
	std::cout << "max(a, b) : " << maxRef << std::endl; // Devrait afficher 10.5 + 2ε
	const Fixed& maxConstRef = Fixed::max(a, c);
	std::cout << "max(a, c) : " << maxConstRef << std::endl; // Devrait afficher 10.5 + 2ε
}*/

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;

	std::cout << a << std::endl;
	
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
	