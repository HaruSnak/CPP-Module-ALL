#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	Animal* j[50];

	std::cout << "\033[31mINITIALIZATION\033[0m" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
		std::cout << "\033[34m" << i << ": \033[0m";
		if (i < 25)
			j[i] = new Dog();
		else
			j[i] = new Cat();
		std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
	}
	std::cout << std::endl << "\033[31mDESTRUCTION\033[0m" << std::endl;
	for (int k = 0; k < 50; k++)
	{
		std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
		std::cout << "\033[34m" << k << ": \033[0m";
		delete j[k];
		std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
	}
	Dog *a = new Dog();
	Dog *b = new Dog();
	Cat *d = new Cat();
	d->setIdeasCat(10, "MIAAAOOUUUUUUUUUUU!");
	d->setIdeasCat(55, "MIAOUU HUNGRY!");
	Cat *c = new Cat(*d);

	std::cout << std::endl << "\033[32m CLASS C\033[0m" << std::endl;
	c->getIdeasCat();
	a->setIdeasDog(1, "Hello, I'm a big dog!");
	a->setIdeasDog(2, "Miaou Miaou ? Wof ? Wof Wof! ");
	std::cout << std::endl << "\033[32m CLASS A\033[0m" << std::endl;
	a->getIdeasDog();
	b->setIdeasDog(5, "WOOOOOOOOOOOOOOOOFFFF! Wof Wof!");
	b->setIdeasDog(1, "Wof Wof 42!");
	std::cout << std::endl << "\033[32m CLASS B\033[0m" << std::endl;
	b->getIdeasDog();
	*a = *b;
	std::cout << std::endl << "\033[32m CLASS A\033[0m" << std::endl;
	a->getIdeasDog();
	delete (a);
	delete (b);
	delete (c);
	delete (d);
	return (0);
}