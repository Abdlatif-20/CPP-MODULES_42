/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Getfile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:48:58 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/23 13:41:23 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETFILE_HPP
#define GETFILE_HPP

#include <iostream>
#include <fstream>
#include <string>


class Getfile{
	private:
		std::string file;
	public:
		std::string	getFile();
		void	setFile(std::string file);
};

void    openFile(char **av);
void	findAndReplace(std::string& file, std::string s1, std::string s2, const std::string& fileName);
#endif