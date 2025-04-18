/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:40:18 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:42:53 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

int main(void)
{
	Animal* j[50];

	color::red("INITIALIZATION");
	for (int i = 0; i < 50; i++)
	{
		color::green("---------------------------------------");
		std::cout << "\033[34m" << i << ": ";
		if (i < 25)
			j[i] = new Dog();
		else
			j[i] = new Cat();
		color::green("---------------------------------------");
	}
	color::red("DESTRUCTION");
	for (int k = 0; k < 50; k++)
	{
		color::green("---------------------------------------");
		std::cout << "\033[34m" << k << ": ";
		delete j[k];
		color::green("---------------------------------------");
	}
	Dog *a = new Dog();
	Dog *b = new Dog();
	Cat *d = new Cat();
	d->setIdeasCat(10, "MIAAAOOUUUUUUUUUUU!");
	d->setIdeasCat(55, "MIAOUU HUNGRY!");
	Cat *c = new Cat(*d);

	color::red("\033[32m CLASS C");
	c->getIdeasCat();
	a->setIdeasDog(1, "Hello, I'm a big dog!");
	a->setIdeasDog(2, "Miaou Miaou ? Wof ? Wof Wof! ");
	color::red("\033[32m CLASS A");
	a->getIdeasDog();
	b->setIdeasDog(5, "WOOOOOOOOOOOOOOOOFFFF! Wof Wof!");
	b->setIdeasDog(1, "Wof Wof 42!");
	color::red("\033[32m CLASS B");
	b->getIdeasDog();
	*a = *b;
	color::red("\033[32m CLASS A");
	a->getIdeasDog();
	delete (a);
	delete (b);
	delete (c);
	delete (d);
	return (0);
}