#ifndef Cat_HPP
# define Cat_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *m_Brain;
	public:
		Cat();
		Cat(Cat const &copy);
		~Cat();
		Cat	&operator=(const Cat &copy);
		void	makeSound(void) const;
		void	setIdeasCat(unsigned int i, std::string addIdeas);
		void	getIdeasCat(void);
};

#endif
