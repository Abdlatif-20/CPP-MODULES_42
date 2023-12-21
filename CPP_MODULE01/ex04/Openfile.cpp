/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Openfile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:47:21 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/21 13:47:10 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Getfile.hpp"

void	printFile(std::string file);

void    openFile(char **av)
{
	std::ifstream outFile;
	std::string line;
	std::string file;
	outFile.open(av[1]);
	if (outFile.is_open())
	{
		while (std::getline(outFile, line))
			file += line + "\n";
		outFile.close();
	}
	else
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	findAndReplace(file, av[2], av[3]);
}

void	findAndReplace(std::string& file, std::string s1, std::string s2)
{
	if (s1 == s2)
	{
		std::cout << "Error: s1 and s2 are the same" << std::endl;
		return ;
	}
	size_t found = 0;
	std::ofstream outputFile("file.replace");

	if (!outputFile.is_open()) {
		std::cerr << "Failed to open the file for writing." << std::endl;
		return ;
	}
	found = file.find(s1, found);
	if (found != std::string::npos) {
		file.erase(found, s1.length());
		file.insert(found, s2);
		findAndReplace(file, s1, s2);
	}
	outputFile << file;
}

void	printFile(std::string file)
{
	int i = 0;
	while (file[i])
	{
		std::cout << file[i];
		i++;
	}
}
