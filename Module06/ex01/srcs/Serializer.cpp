#include "../includes/Serializer.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Serializer::Serializer()
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << "Name constructor called" << std::endl;
	*this = copy;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Serializer::~Serializer()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Serializer& Serializer::operator=(const Serializer& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

