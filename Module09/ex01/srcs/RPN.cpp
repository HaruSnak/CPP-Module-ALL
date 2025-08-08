#include "../includes/RPN.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

RPN::RPN()
{
	std::cout << "RPN constructor called" << std::endl;
	return ;
}

RPN::RPN(const RPN &copy)
{
	std::cout << "RPN constructor copy" << std::endl;
	this->stack = copy.stack;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

RPN& RPN::operator=(const RPN& copy)
{
	if (this != &copy)
	{
		this->stack = copy.stack;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

int RPN::ResultRPN(char *argv)
{
	std::string token;
	std::stringstream ss(argv);
	while (ss >> token)
	{
		if (token == "+" || token == "-" || token == "/" || token == "*")
		{
			if (stack.size() < 2) throw std::runtime_error("Error: Missing operator!");
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			if (token == "+")	stack.push(a + b);
			else if (token == "-")	stack.push(a - b);
			else if (token == "*")	stack.push(a * b);
			else if (token == "/")	stack.push(a / b);
		}
		else if (std::isdigit(token[0]) && token[1] == '\0')
			stack.push(std::atoi(token.c_str()));
		else
			errorType("Invalid input => " + token);
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression!");
	return (stack.top());
}

