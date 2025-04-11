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

	std::cout << std::endl << "\033[32m TYPE CLASSCOLOR_RED + " << std::endl;
	std::cout << "COLOR_RED + "---------------------------------------COLOR_RED + " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	std::cout << "COLOR_RED + "---------------------------------------COLOR_RED + " << std::endl << std::endl;
	std::cout << std::endl << "\033[32m MAKESOUND CLASSCOLOR_RED + " << std::endl;
	std::cout << "COLOR_RED + "---------------------------------------COLOR_RED + " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	l->makeSound();
	meta->makeSound();
	std::cout << "COLOR_RED + "---------------------------------------COLOR_RED + " << std::endl;
	delete meta;
	delete j;
	delete i;
	delete l;
	return (0);
}