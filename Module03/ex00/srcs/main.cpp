/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/13 13:11:36 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

int main(void)
{
    color::red("----- Test 1: Basic Functionality -----");
    ClapTrap clap1("CL4P-TP");
    
    clap1.attack("Bandit");
    clap1.takeDamage(3);
    clap1.beRepaired(2);
    clap1.attack("Psycho");
    clap1.takeDamage(8);
    clap1.beRepaired(5);

    color::red("\n----- Test 2: Energy Management -----");
    ClapTrap clap2("BOT-42");

    for (int i = 0; i < 12; i++) {
        clap2.attack("Target Dummy");
    }
    clap2.beRepaired(1);

    color::red("\n----- Test 3: Health Management -----");
    ClapTrap clap3("TINY-3R");

    clap3.takeDamage(9);
    clap3.beRepaired(1);
    clap3.takeDamage(2);
    clap3.attack("Someone");
    clap3.beRepaired(5);

    color::red("\n----- Test 4: Copy and Assignment -----");
    ClapTrap original("OR1G1NAL");
    original.takeDamage(2);

    ClapTrap copy(original);
    copy.beRepaired(1);

    ClapTrap assigned("TEMP");
    assigned = original;
    assigned.attack("Clone");

    color::red("\n----- Destructors Called Automatically -----");
    return (0);
}
	