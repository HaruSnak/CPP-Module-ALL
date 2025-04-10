#ifndef Data_HPP
# define Data_HPP

# include <iostream>
# include <string>

class Data
{
	private:

	public:
		Data();
		Data(const Data &copy);
		~Data();
		Data& operator=(const Data& copy);
		int value;
		std::string name;
};

#endif
