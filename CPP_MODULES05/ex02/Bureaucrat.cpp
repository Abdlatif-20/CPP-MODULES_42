/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:43:37 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/14 23:17:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade) : name(name)
{
	try
	{
		if (grade > 150)
			throw GradeTooLowException();
		else if (grade < 1)
			throw GradeTooHighException();
		else
			this->grade = grade;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
		exit(1);
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		this->grade = obj.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

const unsigned int &Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (grade - 1 < 1)
			throw GradeTooHighException();
		grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
	
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (grade + 1 > 150)
			throw GradeTooLowException();
		grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
 
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
void	Bureaucrat::signForm(Form form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << name <<" signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << name <<" couldn't sign" << form.getName() << "because <reason>" << std::endl; 
	}
	
}