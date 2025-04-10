/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/10 00:02:45 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sedloser.hpp"

std::string	replaceOccurence(std::string line, char *argv[], size_t pos)
{
	while (pos != std::string::npos)
	{
		line.erase(pos, strlen(argv[2]));
		line.insert(pos, argv[3]);
		pos = line.find(argv[2]);
	}
	return (line);
}

int main(int argc, char *argv[])
{
	std::string line;
	std::string	outputName;
	size_t		pos;

	if (argc != 4 || argv[2][0] == '\0')
		ft_error_base("Three parameters in the following order: a filename and two strings, s1 and s2 (No Empty).\033[0m");
	std::ifstream file(argv[1]);
	if (!file)
		ft_error_base("Invalid file!\033[0m");
	outputName = argv[1];
	outputName += ".replace";
	std::ofstream outputFile(outputName.c_str());
	if (!outputFile)
		ft_error_base("Invalid file!\033[0m");
	while (std::getline(file, line))
	{
		if (std::strcmp(argv[2], argv[3]) != 0)
		{		
			pos = line.find(argv[2]);
			line = replaceOccurence(line, argv, pos);
		}
		outputFile << line << std::endl;
	}
	file.close();
	outputFile.close();
	return (0);
}