#include "../includes/Array.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

template<typename T>
Array<T>::Array()
{
	std::cout << "Default constructor called" << std::endl;
	this->m_size = 0;
	this->m_array = new T[0];
	return ;
}

template<typename T>
Array<T>::Array(unsigned int number)
{
	std::cout << "Default constructor called" << std::endl;
	this->m_size = number;
	this->m_array = new T[number];
	return ;
}

template<typename T>
Array<T>::Array(const Array &copy)
{
	std::cout << "Name constructor called" << std::endl;
	this->m_array = new T[copy.m_size];
	for (size_t i = 0; i < copy.m_size; i++)
		this->m_array[i] = copy.m_array[i];
	this->m_size = copy.m_size;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

template<typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	delete[] this->m_array;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

template<typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		delete[] this->m_array;
		this->m_array = new T[copy.m_size];
		for (size_t i = 0; i < copy.m_size; i++)
			this->m_array[i] = copy.m_array[i];
		this->m_size = copy.m_size;
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](signed int size)
{
	if (size < 0 || size >= static_cast<signed int>(this->m_size))
		throw std::out_of_range("Index is out of range!");
	return (this->m_array[size]);
}

/*------------------------------- FUNCTIONS --------------------------------*/

template<typename T>
size_t Array<T>::size(void) const
{
	return (this->m_size);
}


