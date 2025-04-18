/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/13 14:09:54 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

void test_construction_chain(void)
{
    color::red("\n=== Test 1: Construction/Destruction Chain ===");
    ScavTrap scav("SC4V-TP");
}

void test_combat_functions(void)
{
    color::red("\n=== Test 2: Combat Functions ===");
    ScavTrap scav("Warrior");

    scav.attack("Bandit");
    scav.takeDamage(30);
    scav.beRepaired(15);
}

void test_gate_keeper_mode(void)
{
    color::red("\n=== Test 3: Gate Keeper Special Ability ===");
    ScavTrap scav("Guardian");

    scav.guardGate();
    scav.takeDamage(80);
    scav.guardGate();
    scav.takeDamage(30);
    scav.guardGate();
}

void test_energy_management(void)
{
    color::red("\n=== Test 4: Energy Management ===");
    ScavTrap scav("Battery");

    for (int i = 0; i < 52; i++) {
        scav.attack("Target Dummy");
    }
    scav.guardGate();
}

void test_copy_operations(void)
{
    color::red("\n=== Test 5: Copy Operations ===");
    ScavTrap original("Original");
    original.takeDamage(40);

    ScavTrap copy(original);
    copy.beRepaired(10);

    ScavTrap assigned("Temp");
    assigned = original;
    assigned.guardGate();
}

int main(void)
{
    color::red("===== SCAVTRAP TEST SUITE =====");

    test_construction_chain();
    test_combat_functions();
    test_gate_keeper_mode();
    test_energy_management();
    test_copy_operations();

    color::red("\n===== End of Tests (Automatic Destructor Calls) =====");
    return 0;
}
	