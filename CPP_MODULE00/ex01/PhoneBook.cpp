/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:31:03 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/10 22:00:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	PhoneBook::GetContact(int index)
{
	return (this->contacts[index].getFirstName());
}

PhoneBook::PhoneBook()
{
	this->nbContacts = 0;
}

int	PhoneBook::getNbContacts()
{
	return (this->nbContacts);
}

std::string	check_empty_eof(std::string input, std::string str)
{
	if (input.empty())
	{
		if (std::cin.eof())
			exit(0);
		while (input.empty())
		{
			std::cout << "\033[1;33m" << str << " can't be empty\033[0m" << std::endl;
			std::cout << "Enter " << str << ": ";
			if (std::getline(std::cin, input).eof())
				exit(0);
		}
	}
	return (input);
}

void fill_contact(std::string* input, std::string str)
{
    if (std::getline(std::cin, *input).eof() || input->empty()) {
        *input = check_empty_eof(*input, str);
    }
}

void	PhoneBook::SetContact(int index)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Enter first name: ";
	fill_contact(&firstName, "first name");
	this->contacts[index].setFirstName(firstName);
	std::cout << "Enter last name: ";
	fill_contact(&lastName, "last name");
	this->contacts[index].setLastName(lastName);
	std::cout << "Enter nickname: ";
	fill_contact(&nickname, "nickname");
	this->contacts[index].setNickname(nickname);
	std::cout << "Enter phone number: ";
	fill_contact(&phoneNumber, "phone number");
	this->contacts[index].setPhoneNumber(phoneNumber);
	std::cout << "Enter darkest secret: ";
	fill_contact(&darkestSecret, "darkest secret");
	this->contacts[index].setDarkestSecret(darkestSecret);
	std::cout << "\033[1;32m<< Contact " << index + 1 << " added successfully >>\033[0m" << std::endl;
}

void	PhoneBook::addContact(int index)
{
	this->SetContact(index);
	if (this->nbContacts < 8)
		this->nbContacts++;
}

bool	check_if_degit(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

void	table()
{
	std::cout << std::setw(10) << "index"
		<< "|"
		<< std::setw(10) << "First Name"
		<< "|"
		<< std::setw(10) << "Last Name"
		<< "|"
		<< std::setw(10) << "Nickname"
		<< "|" << std::endl;
}

void	get_index(std::string indexStr, int *index, int nbContacts)
{
	while (1)
	{
		std::cout << "Enter a valid index: ";
		if (std::getline(std::cin, indexStr).eof())
			exit(0);
		if (check_if_degit(indexStr) == false)
		{
			std::cout << "\033[1;31mIndex can't contain letters\033[0m" << std::endl;
			
			continue;
		}
		*index = atoi(indexStr.c_str());
		if (*index <= 0 || *index > nbContacts)
			std::cout << "\033[1;31mInvalid index\033[0m" << std::endl;
		else
			break;
	}
}

std::string	PhoneBook::cut_string(std::string str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
	return (str);
}

void	PhoneBook::searchContact()
{
	int index;
	std::string indexStr;
	std::string str;

	if (this->nbContacts == 0)
	{
		std::cout << "No contacts to search" << std::endl;
		return ;
	}
	table();
	for (int i = 0; i < this->nbContacts; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|"
			<< std::setw(10) << this->cut_string(contacts[i].getFirstName())<< "|"
			<< std::setw(10) << this->cut_string(contacts[i].getLastName()) << "|"
			<< std::setw(10) << this->cut_string(contacts[i].getNickname()) << "|"
			<< std::endl;
	}
	get_index(indexStr, &index, this->nbContacts);
	index--;
	std::cout << "index: " << index + 1 << std::endl
		<< "firstName: " << this->contacts[index].getFirstName() << std::endl
		<< "LastName: " << this->contacts[index].getLastName() << std::endl
		<< "NickName: " << this->contacts[index].getNickname() << std::endl
		<< "PhoneNumber: " << this->contacts[index].getPhoneNumber() << std::endl
		<< "DarkestSecret: " << this->contacts[index].getDarkestSecret() << std::endl;
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
	std::cout << "\033[1;35m" << "Welcome to the phonebook"
	<< "\033[0m" << std::endl;
	while (1)
	{
		std::cout << "Enter a command " << "\033[1;36m"
		<< "(ADD, SEARCH, EXIT)" << "\033[0m"<< ": ";
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			break ;
		else if (command == "ADD")
			phoneBook.addContact(index++ % 8);
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "\033[1;31mInvalid command\033[0m" << std::endl;
	}
	return (0);
}
