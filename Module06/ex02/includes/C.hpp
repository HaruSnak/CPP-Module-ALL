#ifndef C_HPP
# define C_HPP

# include <iostream>
# include <string>
# include "Base.hpp"

class C : public Base
{
	public:
		C();
		C(const C &copy);
		~C();
		C& operator=(const C& copy);
};

#endif
