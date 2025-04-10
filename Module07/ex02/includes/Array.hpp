#ifndef Array_HPP
# define Array_HPP

# include <iostream>
# include <string>
# include <cstdlib>

template<typename T>
class Array
{
	private:
		T *m_array;
		size_t m_size;
	public:
		Array();
		Array(unsigned int number);
		Array(const Array &copy);
		~Array();
		Array& operator=(const Array& copy);
		T& operator[](signed int size);
		size_t	size(void) const;
};

#endif
