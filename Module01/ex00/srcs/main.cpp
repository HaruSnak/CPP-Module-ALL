/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/09 11:03:14 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <string>
#include <sstream>
#include <cstdlib>

void testStackAllocation(void)
{
    std::cout << "\n\033[31m=== Test Stack Allocation ===\033[0m\n";
    std::cout << "\033[32mCreating stack zombie...\033[0m\n";
    Zombie stackZombie("Stacky");
    stackZombie.announce();
    std::cout << "\033[32mLeaving scope - stack zombie should be destroyed automatically\033[0m\n";
}

void testHeapAllocation(void)
{
    std::cout << "\n\033[31m=== Test Heap Allocation ===\033[0m\n";
    
    std::cout << "\033[32mCreating heap zombie...\n";
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    std::cout << "\033[32mExplicitly deleting heap zombie...\033[0m\n";
    delete heapZombie;
    std::cout << "\033[32mLeaving scope - no automatic destruction for heap zombie\033[0m\n";
}

void testRandomChump(void)
{
    std::cout << "\n\033[31m=== Test Random Chump ===\033[0m\n";
    std::cout << "\033[32mCalling randomChump...\033[0m\n";
    randomChump("Chumpy");
    std::cout << "\033[32mrandomChump scope ended - zombie should be destroyed\033[0m\n";
}

void testZombieArmy(void)
{
    std::cout << "\n\033[31m=== Test Zombie Army ===\033[0m\n";
    const int ARMY_SIZE = 3;
    Zombie* army[ARMY_SIZE];
    
    army[0] = newZombie("ZombieSoldier_0");
	army[1] = newZombie("ZombieSoldier_1");
	army[2] = newZombie("ZombieSoldier_2");
    for (int i = 0; i < ARMY_SIZE; i++)
        army[i]->announce();
    std::cout << "\033[32mDestroying zombie army...\033[0m\n";
    for (int i = 0; i < ARMY_SIZE; i++)
        delete army[i];
}

int main(void)
{
    std::cout << "\033[31m===== ZOMBIE TESTS =====\033[0m\n";
    testStackAllocation();
    testHeapAllocation();
    testRandomChump();
    testZombieArmy();
    std::cout << "\n\033[31m===== END OF TESTS =====\033[0m\n";
    return (0);
}