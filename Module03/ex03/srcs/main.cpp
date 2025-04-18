/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 16:54:58 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

void test_construction(void)
{
    color::red("\n=== Testing Construction/Destruction ===");
    DiamondTrap diamond("DIAMOND-1");
}

void test_combat(void)
{
    color::red("\n=== Testing Combat Functions ===");
    DiamondTrap diamond("Warrior");

    diamond.attack("Bandit");
    diamond.takeDamage(50);
    diamond.beRepaired(25);
}

void test_special_abilities(void)
{
    color::red("\n=== Testing Special Abilities ===");
    DiamondTrap diamond("Specialist");

    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();
}

void test_energy_management(void)
{
    color::red("\n=== Testing Energy Limits ===");
    DiamondTrap diamond("Battery");

    for (int i = 0; i < 52; i++) {
        diamond.attack("Target");
    }
    diamond.highFivesGuys();
}

void test_copy_operations(void)
{
    color::red("\n=== Testing Copy Operations ===");
    DiamondTrap original("Original");
    original.takeDamage(30);

    DiamondTrap copy(original);
    copy.whoAmI();

    DiamondTrap assigned("Temp");
    assigned = original;
    assigned.whoAmI();
}

int main(void)
{
    color::red("===== DIAMONDTRAP TEST SUITE =====");

    test_construction();
    test_combat();
    test_special_abilities();
    test_energy_management();
    test_copy_operations();

    color::red("\n===== End of Tests =====");
    return (0);
}
	