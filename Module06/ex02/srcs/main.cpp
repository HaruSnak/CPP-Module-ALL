/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:25:21 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 16:28:02 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/identify.hpp"

Base* generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			color::red("[generate]\033[0m: A");
			return (new A);
		case 1:
			color::red("[generate]\033[0m: B");
			return (new B);
		case 2:
			color::red("[generate]\033[0m: C");
			return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		color::red("[identify(Base*)]\033[0m: A");
	else if (dynamic_cast<B*>(p))
		color::red("[identify(Base*)]\033[0m: B");
	else if (dynamic_cast<C*>(p))
		color::red("[identify(Base*)]\033[0m: C");
	else
		color::err_red("[identify(Base*)]\033[0m: Pointer is NULL");
}

void identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		color::red("[identify(Base&)]\033[0m: A");
	}
	catch (...)
	{
		try {
			(void)dynamic_cast<B&>(p);
			color::red("[identify(Base&)]\033[0m: B");
		}
		catch(...)
		{
			try {
				(void)dynamic_cast<C&>(p);
				color::red("[identify(Base&)]\033[0m: C");
			}
			catch(...)
			{
				color::err_red("[identify(Base&)]\033[0m: Error: Pointer is invalid!");
			}
			
		}
	}
}

int main(void)
{
    const int numTests = 10;

    for (int i = 0; i < numTests; ++i)
	{
        std::cout << color::COLOR_RED + "\n=== Test #" << i + 1 << " ===" << std::endl;;
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }
    return (0);
}