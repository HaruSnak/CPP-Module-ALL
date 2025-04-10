#ifndef Dog_HPP
# define Dog_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *m_Brain;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog	&operator=(const Dog &copy);
		void	makeSound(void) const;
		void	setIdeasDog(unsigned int i, std::string addIdeas);
		void	getIdeasDog(void);
};

#endif
