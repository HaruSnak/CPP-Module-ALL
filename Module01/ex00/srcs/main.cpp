/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/12 16:08:52 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/brain.hpp"

void testStackAllocation(void)
{
    color::red("=== Test Stack Allocation ===");
    color::green("Creating stack zombie...");
    Zombie stackZombie("Stacky");
    stackZombie.announce();
    color::green("Leaving scope - stack zombie should be destroyed automatically");
}

void testHeapAllocation(void)
{
    color::red("=== Test Heap Allocation ===");
    
    color::green("Creating heap zombie...\n");
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    color::green("Explicitly deleting heap zombie...");
    delete heapZombie;
    color::green("Leaving scope - no automatic destruction for heap zombie");
}

void testRandomChump(void)
{
    color::red("=== Test Random Chump ===");
    color::green("Calling randomChump...");
    randomChump("Chumpy");
    color::green("randomChump scope ended - zombie should be destroyed");
}

void testZombieArmy(void)
{
    color::red("=== Test Zombie Army ===");
    const int ARMY_SIZE = 3;
    Zombie* army[ARMY_SIZE];
    
    army[0] = newZombie("ZombieSoldier_0");
	army[1] = newZombie("ZombieSoldier_1");
	army[2] = newZombie("ZombieSoldier_2");
    for (int i = 0; i < ARMY_SIZE; i++)
        army[i]->announce();
    color::green("Destroying zombie army...");
    for (int i = 0; i < ARMY_SIZE; i++)
        delete army[i];
}

int main(void)
{
    color::red("===== ZOMBIE TESTS =====");
    testStackAllocation();
    testHeapAllocation();
    testRandomChump();
    testZombieArmy();
    color::red("===== END OF TESTS =====");
    return (0);
}