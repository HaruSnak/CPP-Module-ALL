#include "../includes/Span.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Span::Span(unsigned int maxNbr)
{
	std::cout << "Span constructor called" << std::endl;
	if (maxNbr < std::numeric_limits<unsigned int>::min() || maxNbr > std::numeric_limits<unsigned int>::max())
	{
		throw std::runtime_error("Error: Exceeding max or min values!");
	}
	this->N = maxNbr;
}

Span::Span(const Span &copy) : N(copy.N)
{
	std::cout << "Span constructor copy" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	Span::addNumber(unsigned int number)
{
	if (number < std::numeric_limits<unsigned int>::min() || number > std::numeric_limits<unsigned int>::max())
		throw std::runtime_error("Error: Exceeding max or min values!");
	if (vec.size() < this->N)
	{
		vec.push_back(number);
	}
	else
		throw std::logic_error("Error: Span is full!");
}

int	Span::shortestSpan(void)
{
	if (this->vec.empty() || this->vec.size() == 1)
	{
		throw std::logic_error("Error: Vector empty or size == 1!");
	}
	std::vector<int> tmp = this->vec;
	std::sort(tmp.begin(), tmp.end());
	int value = abs(tmp[0] - tmp[1]);
	//std::cout << value << std::endl;
	for (int i = 0; static_cast<long unsigned int>(i) != tmp.size(); i++)
	{
		if (static_cast<long unsigned int>(i) + 1 < tmp.size() && abs(tmp[i] - tmp[i + 1]) < value)
			value = abs(tmp[i] - tmp[i + 1]);
	}
	return (value);
}

int	Span::longestSpan(void)
{
	if (this->vec.empty() || this->vec.size() == 1)
	{
		throw std::logic_error("Error: Vector empty or size == 1!");
	}
	std::vector<int> tmp = this->vec;

	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + this->vec.size() > this->N)
		throw std::logic_error("Error: Vector index overflow!");
	else if (std::distance(begin, end) == 0)
		throw std::logic_error("Error: No values ​​in the vectors put as arguments.");
	vec.insert(vec.end(), begin, end);
	return ;
}



