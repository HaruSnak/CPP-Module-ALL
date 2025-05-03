/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:27:40 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/29 18:32:11 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<int>::container_type Container;
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator c_iterator;
		iterator  begin(void);
		iterator end(void);
		c_iterator begin(void) const;
		c_iterator end(void) const;
		
		
};

#endif
