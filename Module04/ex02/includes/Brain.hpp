#ifndef Brain_HPP
# define Brain_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain &copy);
		~Brain();
		Brain& operator=(Brain& copy);
		void	setIdeas(unsigned int i, std::string addIdeas);
		void	getIdeas(void) const;
};

#endif
