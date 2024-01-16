/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:40:46 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/16 14:43:52 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
		this->target = obj.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	time_t currentTime = time(0);
	if (this->isSign() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << "Brrrrrrrrr" << std::endl;
	if (currentTime % 2 == 0)
		std::cout << this->target << " has been robotomized successfully " << std::endl;
	else
		std::cout << this->target << " has not been robotomized successfully " << std::endl;
}