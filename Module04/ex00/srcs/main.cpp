/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:28:09 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:31:03 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/polymorphism.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* l = new WrongCat();

	color::red("TYPE CLASS");
	color::green("---------------------------------------");
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	color::green("---------------------------------------");
	color::red("MAKESOUND CLASS");
	color::green("---------------------------------------");
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	l->makeSound();
	meta->makeSound();
	color::green("---------------------------------------");
	delete meta;
	delete j;
	delete i;
	delete l;
	return (0);
}