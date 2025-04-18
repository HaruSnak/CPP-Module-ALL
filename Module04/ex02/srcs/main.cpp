/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:11:07 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 18:46:12 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/abstract_class.hpp"

int main()
{
	Animal* j[50];

	color::red("INITIALIZATION");
	for (int i = 0; i < 50; i++)
	{
		color::red("---------------------------------------");
		std::cout << "\033[33m" << i << ": ";
		if (i < 25)
			j[i] = new Dog();
		else
			j[i] = new Cat();
		color::red("---------------------------------------");
	}
	color::red("DESTRUCTION");
	for (int k = 0; k < 50; k++)
	{
		color::red("---------------------------------------");
		std::cout << "\033[33m" << k << ": ";
		delete j[k];
		color::red("---------------------------------------");
	}
	Dog *a = new Dog();
	Dog *b = new Dog();
	Cat *d = new Cat();
	d->setIdeasCat(10, "MIAAAOOUUUUUUUUUUU!");
	d->setIdeasCat(55, "MIAOUU HUNGRY!");
	Cat *c = new Cat(*d);

	color::red("CLASS C");
	c->getIdeasCat();
	a->setIdeasDog(1, "Hello, I'm a big dog!");
	a->setIdeasDog(2, "Miaou Miaou ? Wof ? Wof Wof! ");
	color::red("CLASS A");
	a->getIdeasDog();
	b->setIdeasDog(5, "WOOOOOOOOOOOOOOOOFFFF! Wof Wof!");
	b->setIdeasDog(100, "Wof Wof 42!");
	color::red("CLASS B");
	b->getIdeasDog();
	*a = *b;
	color::red("CLASS A");
	a->getIdeasDog();
	delete (a);
	delete (b);
	delete (c);
	delete (d);
	return (0);
}