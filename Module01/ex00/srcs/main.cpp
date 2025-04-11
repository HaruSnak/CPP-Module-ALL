/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/11 22:13:13 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <string>
#include <sstream>
#include <cstdlib>

const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_NONE = "\033[0m";

void testStackAllocation(void)
{
    std::cout << COLOR_RED + "=== Test Stack Allocation ===" + COLOR_NONE << std::endl;
    std::cout << COLOR_GREEN + "Creating stack zombie..." + COLOR_NONE << std::endl;
    Zombie stackZombie("Stacky");
    stackZombie.announce();
    std::cout << COLOR_GREEN + "Leaving scope - stack zombie should be destroyed automatically" + COLOR_NONE << std::endl;
}

void testHeapAllocation(void)
{
    std::cout << COLOR_RED + "=== Test Heap Allocation ===" + COLOR_NONE << std::endl;
    
    std::cout << COLOR_GREEN + "Creating heap zombie...\n";
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    std::cout << COLOR_GREEN + "Explicitly deleting heap zombie..." + COLOR_NONE << std::endl;
    delete heapZombie;
    std::cout << COLOR_GREEN + "Leaving scope - no automatic destruction for heap zombie" + COLOR_NONE << std::endl;
}

void testRandomChump(void)
{
    std::cout << COLOR_RED + "=== Test Random Chump ===" + COLOR_NONE << std::endl;
    std::cout << COLOR_GREEN + "Calling randomChump..." + COLOR_NONE << std::endl;
    randomChump("Chumpy");
    std::cout << COLOR_GREEN + "randomChump scope ended - zombie should be destroyed" + COLOR_NONE << std::endl;
}

void testZombieArmy(void)
{
    std::cout << COLOR_RED + "=== Test Zombie Army ===" + COLOR_NONE << std::endl;
    const int ARMY_SIZE = 3;
    Zombie* army[ARMY_SIZE];
    
    army[0] = newZombie("ZombieSoldier_0");
	army[1] = newZombie("ZombieSoldier_1");
	army[2] = newZombie("ZombieSoldier_2");
    for (int i = 0; i < ARMY_SIZE; i++)
        army[i]->announce();
    std::cout << COLOR_GREEN + "Destroying zombie army..." + COLOR_NONE << std::endl;
    for (int i = 0; i < ARMY_SIZE; i++)
        delete army[i];
}

int main(void)
{
    std::cout << COLOR_RED + "===== ZOMBIE TESTS =====" + COLOR_NONE << std::endl;
    testStackAllocation();
    testHeapAllocation();
    testRandomChump();
    testZombieArmy();
    std::cout << COLOR_RED + "===== END OF TESTS =====" + COLOR_NONE << std::endl;
    return (0);
}