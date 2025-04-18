/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/12 17:04:49 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/harl_base.hpp"

int main(void)
{
    Harl harl;

    color::red("===== HARL'S COMPLAINTS =====\n");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    color::red("===== EDGE CASES =====");
    harl.complain("");
    harl.complain("debug");
    harl.complain("WARN");
    harl.complain("CRITICAL");
    color::red("===== END OF TESTS =====");
    return (0);
}