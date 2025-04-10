#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* l = new WrongCat();

	std::cout << std::endl << "\033[32m TYPE CLASS\033[0m" << std::endl;
	std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	std::cout << "\033[31m---------------------------------------\033[0m" << std::endl << std::endl;
	std::cout << std::endl << "\033[32m MAKESOUND CLASS\033[0m" << std::endl;
	std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	l->makeSound();
	meta->makeSound();
	std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete l;
	return (0);
}