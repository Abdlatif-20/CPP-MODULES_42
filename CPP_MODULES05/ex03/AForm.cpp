/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:14:21 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/15 21:44:16 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AForm.hpp"

AForm::AForm() : name("default"), sign(false), gradeSign(1), gradeExecute(1)
{
}

AForm::AForm(const std::string& name, const unsigned int& gradeSign, const unsigned int& gradeExecute) : name(name), sign(false), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.name), gradeSign(obj.gradeSign), gradeExecute(obj.gradeExecute)
{
	*this = obj;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		this->sign = obj.sign;
	return (*this);
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return (this->name);
}

const bool &AForm::isSign() const
{
	return (this->sign);
}

const unsigned int &AForm::getGradeSign() const
{
	return (this->gradeSign);
}

const unsigned int &AForm::getGradeExecute() const
{
	return (this->gradeExecute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << " is " << (obj.isSign() ? "signed" : "not signed")
		<< " and require a grade of "<< obj.getGradeSign() << " to be signed and "
		<< obj.getGradeExecute() << " to be executed";
	return (os);
}

void	AForm::beSigned(Bureaucrat& bure)
{
	if (bure.getGrade() > gradeSign)
		throw GradeTooLowException();
	sign = true;
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}