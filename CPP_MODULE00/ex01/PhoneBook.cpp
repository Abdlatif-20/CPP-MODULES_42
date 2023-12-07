/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:31:03 by aben-nei          #+#    #+#             */
/*   Updated: 2023/10/09 19:48:21 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::GetContact(int index)
{
	return (this->contacts[index].getFirstName());
}

void    PhoneBook::setNumber(int index)
{
	this->nbContacts = index;
}

int    PhoneBook::getNbContacts()
{
	return (this->nbContacts);
}

void        PhoneBook::SetContact(int index)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Enter first name: ";
	if (std::getline(std::cin, firstName).eof())
		exit(0);
	this->contacts[index].setFirstName(firstName);
	std::cout << "Enter last name: ";
	if (std::getline(std::cin, lastName).eof())
		exit(0);
	this->contacts[index].setLastName(lastName);
	std::cout << "Enter nickname: ";
	if (std::getline(std::cin, nickname).eof())
		exit(0);
	this->contacts[index].setNickname(nickname);
	std::cout << "Enter phone number: ";
	if (std::getline(std::cin, phoneNumber).eof())
		exit(0);
	this->contacts[index].setPhoneNumber(phoneNumber);
	std::cout << "Enter darkest secret: ";
	if (std::getline(std::cin, darkestSecret).eof())
		exit(0);
	this->contacts[index].setDarkestSecret(darkestSecret);
}

void    PhoneBook::addContact(int index)
{
	this->SetContact(index);
	if (this->nbContacts < 8)
		this->nbContacts++;
}

void    PhoneBook::searchContact()
{
	int index;
	std::string indexStr;

	if (this->nbContacts == 0)
	{
		std::cout << "No contacts to search" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "index"
			  << "|"
			  << std::setw(10) << "First Name"
			  << "|"
			  << std::setw(10) << "Last Name"
			  << "|"
			  << std::setw(10) << "Nickname"
			  << "|" << std::endl;
	for (int i = 0; i < this->nbContacts; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  <<std::setw(10) << this->contacts[i].getFirstName().substr(0, 10) + "." << "|"
				  << std::setw(10) << this->contacts[i].getLastName().substr(0, 10) + "." << "|"
				  << std::setw(10) << this->contacts[i].getNickname().substr(0, 10) + "." << "|" << std::endl;
		}
	std::cout << "Enter an index: ";
	if (std::getline(std::cin, indexStr).eof())
		exit(0);
	index = atoi(indexStr.c_str());
	if (index < 0 || index >= this->nbContacts)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "index"
			  << "|"
			  << std::setw(10) << "First Name"
			  << "|"
			  << std::setw(10) << "Last Name"
			  << "|"
			  << std::setw(10) << "Nickname"
			  << "|"
			  << std::setw(10) << "Phone Number"
			  << "|"
			  << std::setw(10) << "Darkest Secret"
			  << "|" << std::endl;
	std::cout << std::setw(10) << index
				<< std::setw(10) << this->contacts[index].getFirstName() << "|"
				<< std::setw(10) << this->contacts[index].getLastName() << "|"
				<< std::setw(10) << this->contacts[index].getNickname() << "|"
				<< std::setw(10) << this->contacts[index].getPhoneNumber() << "|"
				<< std::setw(10) << this->contacts[index].getDarkestSecret()
				<< "|"<< std::endl;
}

int main(int ac, char **av)
{
	(void)av;
	PhoneBook phoneBook;
	std::string command;
	int index;

	if (ac != 1)
		return (0);
	index = 0;
	phoneBook.setNumber(0);
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			break ;
		else if (command == "ADD")
			phoneBook.addContact(index++ % 8);
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}