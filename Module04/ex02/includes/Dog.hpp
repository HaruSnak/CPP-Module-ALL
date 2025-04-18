/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:53:21 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:53:22 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

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
