/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/12 16:39:32 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/needless_force.hpp"

void testHumanA(void)
{
    color::red("\n--- Testing HumanA ---");
    
    Weapon sword("sharp sword" );
    HumanA arthur("Arthur", sword);
    
    arthur.attack();
    
    sword.setType("enchanted sword");
    arthur.attack();
    Weapon axe("double-headed axe");
    HumanA gimli("Gimli", axe);
    gimli.attack();
}

void testHumanB(void)
{
    color::red("\n--- Testing HumanB ---");
    
    HumanB legolas("Legolas");
    legolas.attack();

    Weapon bow("longbow");
    legolas.setWeapon(bow);
    legolas.attack();
    bow.setType("elven longbow");
    legolas.attack();
    
    Weapon knives("twin knives");
    legolas.setWeapon(knives);
    legolas.attack();
}

void edgeCases(void)
{
    color::red("\n--- Edge Cases ---");
    
    Weapon unnamed("");
    HumanA nobody("Nobody", unnamed);
    nobody.attack();
    
    HumanB ghost("Ghost");
    ghost.attack();
}

int main(void)
{
    color::red("===== WEAPON TEST SUITE =====");
    testHumanA();
    testHumanB();
    edgeCases();
    color::red("\n===== TESTS COMPLETE =====");
    return (0);
}