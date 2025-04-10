/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/09 18:08:32 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

void testHumanA() {
    std::cout << "\n\033[31m--- Testing HumanA ---\033[0m\n";
    
    Weapon sword("\033[32msharp sword\033[0m");
    HumanA arthur("\033[32mArthur\033[0m", sword);
    
    arthur.attack();
    
    sword.setType("\033[32menchanted sword\033[0m");
    arthur.attack();
    Weapon axe("\033[32mdouble-headed axe\033[0m");
    HumanA gimli("\033[32mGimli\033[0m", axe);
    gimli.attack();
}

void testHumanB() {
    std::cout << "\n\033[31m--- Testing HumanB ---\033[0m\n";
    
    HumanB legolas("\033[32mLegolas\033[0m");
    legolas.attack();

    Weapon bow("\033[32mlongbow\033[0m");
    legolas.setWeapon(bow);
    legolas.attack();
    bow.setType("\033[32melven longbow\033[0m");
    legolas.attack();
    
    Weapon knives("\033[32mtwin knives\033[0m");
    legolas.setWeapon(knives);
    legolas.attack();
}

void edgeCases() {
    std::cout << "\n\033[31m--- Edge Cases ---\033[0m\n";
    
    Weapon unnamed("");
    HumanA nobody("\033[32mNobody\033[0m", unnamed);
    nobody.attack();
    
    HumanB ghost("\033[32mGhost\033[0m");
    ghost.attack();
}

int main() {
    std::cout << "\033[31m===== WEAPON TEST SUITE =====\033[0m\n";
    testHumanA();
    testHumanB();
    edgeCases();
    std::cout << "\n\033[31m===== TESTS COMPLETE =====\033[0m\n";
    return 0;
}