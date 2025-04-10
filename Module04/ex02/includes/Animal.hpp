#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(Animal const &copy);
		virtual ~Animal();
		Animal	&operator=(Animal const &copy);
		virtual void	makeSound(void) const = 0;
		virtual  const std::string&	getType(void) const;
};

#endif
