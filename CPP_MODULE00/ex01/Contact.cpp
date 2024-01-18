/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:30:52 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/17 17:35:48 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void    Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void    Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

bool check_PhoneNumber(std::string phoneNumber)
{
	for (int i = 0; phoneNumber[i]; i++)
	{
		if (!std::isdigit(phoneNumber[i]))
			return (false);
	}
	return (true);
}

void    Contact::setPhoneNumber(std::string phoneNumber)
{
	while (!check_PhoneNumber(phoneNumber))
	{
		std::cout << "\033[1;31mPhone number can't contain letters\033[0m" << std::endl;
		std::cout << "Enter phone number: ";
		fill_contact(&phoneNumber, "phone number");
	}
	this->phoneNumber = phoneNumber;
}

void    Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName()
{
	return (this->firstName);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}

std::string	Contact::getNickname()
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}
