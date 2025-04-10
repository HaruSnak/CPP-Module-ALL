#ifndef B_HPP
# define B_HPP

# include <iostream>
# include <string>
# include "Base.hpp"

class B : public Base
{
	public:
		B();
		B(const B &copy);
		~B();
		B& operator=(const B& copy);
};

#endif
