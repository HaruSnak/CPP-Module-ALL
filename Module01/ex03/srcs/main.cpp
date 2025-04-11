/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/11 22:27:12 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_NONE = "\033[0m";

void testHumanA() {
    std::cout << COLOR_RED + "\n--- Testing HumanA ---" + COLOR_NONE << std::endl;;
    
    Weapon sword("sharp sword");
    HumanA arthur("Arthur", sword);
    
    arthur.attack();
    
    sword.setType("enchanted sword");
    arthur.attack();
    Weapon axe("double-headed axe");
    HumanA gimli("Gimli", axe);
    gimli.attack();
}

void testHumanB() {
    std::cout << COLOR_RED + "\n--- Testing HumanB ---" + COLOR_NONE << std::endl;;
    
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

void edgeCases() {
    std::cout << COLOR_RED + "\n--- Edge Cases ---" + COLOR_NONE << std::endl;;
    
    Weapon unnamed("");
    HumanA nobody("Nobody", unnamed);
    nobody.attack();
    
    HumanB ghost("Ghost");
    ghost.attack();
}

int main() {
    std::cout << COLOR_RED + "===== WEAPON TEST SUITE =====" + COLOR_NONE << std::endl;;
    testHumanA();
    testHumanB();
    edgeCases();
    std::cout << COLOR_RED + "\n===== TESTS COMPLETE =====" + COLOR_NONE << std::endl;;
    return 0;
}