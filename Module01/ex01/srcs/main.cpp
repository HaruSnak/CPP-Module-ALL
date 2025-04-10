/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/09 12:08:03 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void testZombieHorde(int size, const std::string& name) {
    std::cout << "\n\033[31m=== TESTING HORDE OF " << size << " ZOMBIES NAMED " << name << " ===\033[0m\n";
    Zombie* horde = zombieHorde(size, name);
    if (!horde) {
        std::cerr << "\033[32mHorde creation failed!\033[0m\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        horde[i].announce();
    }
    std::cout << "\033[32mDestroying the horde...\033[0m\n";
    delete[] horde;
}

void edgeCasesTests() {
    std::cout << "\n\033[31m=== EDGE CASES TESTS ===\033[0m\n";
    std::cout << "\n\033[32mTest with 0 zombies:\033[0m\n";
    Zombie* emptyHorde = zombieHorde(0, "Invisible");
    if (!emptyHorde)
        std::cout << "\033[32mCorrectly returned nullptr for 0 zombies\033[0m\n";
    delete[] emptyHorde;
    std::cout << "\n\033[32mTest with empty name:\033[0m\n";
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

int main() {
    std::cout << "\033[31m===== ZOMBIE HORDE TESTS =====\033[0m\n";
    testZombieHorde(5, "Hordie");
    testZombieHorde(3, "Runner");
    testZombieHorde(1, "Lonely");
    edgeCasesTests();
    std::cout << "\n\033[31m===== END OF TESTS =====\033[0m\n";
    return 0;
}