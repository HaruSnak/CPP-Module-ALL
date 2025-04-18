/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:52:21 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 16:03:03 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/convert.hpp"

int main()
{
    Data original;
    original.value = 42;
    original.name = "Test Object";

    color::mix_rg("Original address: ") << &original << std::endl;
    color::mix_rg("Original values: ") << original.value << ", " << original.name << std::endl;

    uintptr_t serialized = Serializer::serialize(&original);
    color::mix_rg("Serialized value: ") << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    color::mix_rg("Deserialized address: ") << deserialized << std::endl;
	
    if (deserialized == &original)
	{
        color::green("\nSUCCESS: Pointers match!") << std::endl;
        color::mix_rg("Deserialized values: ") << deserialized->value << ", " << deserialized->name << color::COLOR_NONE << std::endl;
    }
	else 
        color::red("\nERROR: Pointers don't match!");
    return (0);
}