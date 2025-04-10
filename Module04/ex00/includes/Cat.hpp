#ifndef Cat_HPP
# define Cat_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &copy);
		~Cat();
		Cat	&operator=(Cat const &copy);
		void	makeSound(void) const;
};

#endif
