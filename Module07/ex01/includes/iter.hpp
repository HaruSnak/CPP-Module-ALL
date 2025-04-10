#ifndef iter_HPP
# define iter_HPP

# include <iostream>
# include <string>
# include <cstddef>

template<typename T>
void	iter(T* table, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
	{
		f(table[i]);
	}
}

#endif
