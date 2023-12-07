/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Getfile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:52:52 by aben-nei          #+#    #+#             */
/*   Updated: 2023/10/20 12:56:52 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Getfile.hpp"

std::string	Getfile::getFile()
{
	return (this->file);
}

void	Getfile::setFile(std::string file)
{
	this->file = file;
}
