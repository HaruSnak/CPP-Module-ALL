#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base* generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << COLOR_RED + "[generate]\033[0m: A" << std::endl;
			return (new A);
		case 1:
			std::cout << COLOR_RED + "[generate]\033[0m: B" << std::endl;
			return (new B);
		case 2:
			std::cout << COLOR_RED + "[generate]\033[0m: C" << std::endl;
			return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << COLOR_RED + "[identify(Base*)]\033[0m: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << COLOR_RED + "[identify(Base*)]\033[0m: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << COLOR_RED + "[identify(Base*)]\033[0m: C" << std::endl;
	else
		std::cerr << COLOR_RED + "[identify(Base*)]\033[0m: Pointer is NULL" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << COLOR_RED + "[identify(Base&)]\033[0m: A" << std::endl;
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << COLOR_RED + "[identify(Base&)]\033[0m: B" << std::endl;
		}
		catch(...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << COLOR_RED + "[identify(Base&)]\033[0m: C" << std::endl;
			}
			catch(...)
			{
				std::cerr << COLOR_RED + "[identify(Base&)]\033[0m: Error: Pointer is invalid!" << std::endl;
			}
			
		}
	}
}

int main(void)
{
    const int numTests = 10;

    for (int i = 0; i < numTests; ++i)
	{
        std::cout << "\n=== Test #" << i + 1 << " ===" << std::endl;
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }
    return (0);
}