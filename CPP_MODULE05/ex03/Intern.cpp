/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:53:05 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/16 14:19:07 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return (*this);
}

Intern::~Intern()
{
}

static int	getFormIndex(const std::string& name)
{
	std::string names[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int		i = 0;

	while (i < 3 && names[i] != name)
		i++;
	return (i);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int		index = getFormIndex(name);
	AForm*	form;

	switch (index)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break;
		case 1:
			form = new ShrubberyCreationForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw FormDoesNotExistException();
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return ("Form does not exist");
}