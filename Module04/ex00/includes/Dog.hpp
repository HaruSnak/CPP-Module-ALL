#ifndef Dog_HPP
# define Dog_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &copy);
		~Dog();
		Dog	&operator=(Dog const &copy);
		void	makeSound(void) const;
};

#endif
