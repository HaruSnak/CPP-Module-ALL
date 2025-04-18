/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/13 15:39:24 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

void testInheritanceChain() {
    color::red("\n=== Testing Construction/Destruction Chain ===");
    FragTrap frag("FR4G-TP");
}

void testCombat() {
    color::red("\n=== Testing Combat Functions ===");
    FragTrap frag("Warrior");

    frag.attack("Bandit");
    frag.takeDamage(50);
    frag.beRepaired(25);
	std::cout << color::COLOR_NONE;
}

void testSpecialAbility() {
    color::red("\n=== Testing Special Ability ===");
    FragTrap frag("Happy");

    frag.highFivesGuys();
    frag.takeDamage(99);
    frag.highFivesGuys();
    frag.takeDamage(1);
    frag.highFivesGuys();
}

void testEnergyManagement() {
    color::red("\n=== Testing Energy Limits ===");
    FragTrap frag("Battery");

    for (int i = 0; i < 102; i++) {
        frag.attack("Target");
    }
    frag.highFivesGuys();
}

void testCopyOperations() {
    color::red("\n=== Testing Copy Operations ===");
    FragTrap original("Original");
    original.takeDamage(30);

    FragTrap copy(original);
    copy.beRepaired(10);

    FragTrap assigned("Temp");
    assigned = original;
    assigned.highFivesGuys();
}

int main() {
    color::red("===== FRAGTRAP TEST SUITE =====");

    testInheritanceChain();
    testCombat();
    testSpecialAbility();
    testEnergyManagement();
    testCopyOperations();

    color::red("\n===== End of Tests (Destructors Called) =====");
    return (0);
}
	