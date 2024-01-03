/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Openfile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:47:21 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/24 21:55:09 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Getfile.hpp"

void    openFile(char **av)
{
	std::ifstream outFile(av[1]);
	std::string line;
	std::string file;

	if (outFile.is_open())
	{
		while (std::getline(outFile, line))
			file += line + "\n";
		if (file.empty())
		{
			std::cout << "Error: file is empty" << std::endl;
			outFile.close();
			return ;
		}
		outFile.close();
	}
	else
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	findAndReplace(file, av[2], av[3], av[1]);
}

void	findAndReplace(std::string& file, std::string s1, std::string s2, const std::string& fileName)
{
	if (s1 == s2)
	{
		std::cout << "Error: s1 and s2 are the same" << std::endl;
		return ;
	}
	std::ofstream outputFile(fileName + ".replace");
	if (s1.empty())
	{
		outputFile << file;
		return ;
	}
	static size_t found = 0;
	if (!outputFile.is_open()) {
		std::cerr << "Failed to open the file for writing." << std::endl;
		return ;
	}
	found = file.find(s1, found);
	if (found != std::string::npos) {
		file.erase(found, s1.length());
		file.insert(found, s2);
		found += s2.length();
		findAndReplace(file, s1, s2, fileName);
	}
	outputFile << file;
}
