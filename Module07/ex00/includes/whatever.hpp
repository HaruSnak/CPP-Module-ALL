#ifndef whatever_HPP
# define whatever_HPP

# include <iostream>
# include <string>

template<typename T>
void	swap(T& a, T& b)
{
	T temp = b;
	b = a;
	a = temp;
	return ;
}

template<typename T>
T	min(T& a, T& b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

template<typename T>
T	max(T& a, T& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
