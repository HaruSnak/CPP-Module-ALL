/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/11 22:16:00 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_NONE = "\033[0m";

void testZombieHorde(int size, const std::string& name)
{
    std::cout << COLOR_RED + "\n=== TESTING HORDE OF " << size << " ZOMBIES NAMED " << name << " ===n" + COLOR_NONE << std::endl;
    Zombie* horde = zombieHorde(size, name);
    if (!horde) {
        std::cerr << COLOR_RED + "Horde creation failed!" + COLOR_NONE << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        horde[i].announce();
    }
    std::cout << COLOR_GREEN + "Destroying the horde..." + COLOR_NONE << std::endl;
    delete[] horde;
}

void edgeCasesTests(void)
{
    std::cout << COLOR_RED + "\n=== EDGE CASES TESTS ===" + COLOR_NONE << std::endl;
    std::cout << COLOR_GREEN + "\nTest with 0 zombies:" + COLOR_NONE << std::endl;
    Zombie* emptyHorde = zombieHorde(0, "Invisible");
    if (!emptyHorde)
        std::cout << COLOR_RED + "Correctly returned nullptr for 0 zombies" + COLOR_NONE << std::endl;
    delete[] emptyHorde;
    std::cout << COLOR_GREEN + "\nTest with empty name:" + COLOR_NONE << std::endl;
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
    std::cout << COLOR_RED + "===== ZOMBIE HORDE TESTS =====" + COLOR_NONE << std::endl;
    testZombieHorde(5, "Hordie");
    testZombieHorde(3, "Runner");
    testZombieHorde(1, "Lonely");
    edgeCasesTests();
    std::cout << COLOR_RED + "\n===== END OF TESTS =====" + COLOR_NONE << std::endl;
    return 0;
}