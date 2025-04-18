/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:53:19 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:53:20 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

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
