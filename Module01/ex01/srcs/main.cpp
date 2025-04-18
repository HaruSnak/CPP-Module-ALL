/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/12 16:23:49 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moar_brainz.hpp"

void testZombieHorde(int size, const std::string& name)
{
    std::cout << color::COLOR_RED + "\n=== TESTING HORDE OF "
	<< size << " ZOMBIES NAMED " << name << " ===\n" + color::COLOR_NONE;
    Zombie* horde = zombieHorde(size, name);
    if (!horde) {
        color::err_red("Horde creation failed!");
        return;
    }
    for (int i = 0; i < size; i++) {
        horde[i].announce();
    }
    color::green("Destroying the horde...");
    delete[] horde;
}

void edgeCasesTests(void)
{
    color::red("\n=== EDGE CASES TESTS ===");
    color::green("\nTest with 0 zombies:");
    Zombie* emptyHorde = zombieHorde(0, "Invisible");
    if (!emptyHorde)
        color::err_red("Correctly returned nullptr for 0 zombies");
    delete[] emptyHorde;
    color::green("\nTest with empty name:");
    Zombie* namelessHorde = zombieHorde(3, "");
    if (namelessHorde)
	{
        for (int i = 0; i < 3; i++) 
		{
            namelessHorde[i].announce();
        }
        delete[] namelessHorde;
    }
}

int main(void)
{
    color::red("===== ZOMBIE HORDE TESTS =====");
    testZombieHorde(5, "Hordie");
    testZombieHorde(3, "Runner");
    testZombieHorde(1, "Lonely");
    edgeCasesTests();
    color::red("\n===== END OF TESTS =====");
    return 0;
}