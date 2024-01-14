/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:14:17 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/14 23:47:45 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const unsigned int	gradeSign;
		const unsigned int	gradeExecute;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		AForm();
		AForm(std::string name, unsigned int gradeSign, unsigned int gradeExecute);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		~AForm();

		const std::string &getName() const;
		const bool &isSign() const;
		const unsigned int &getGradeSign() const;
		const unsigned int &getGradeExecute() const;
		void	beSigned(Bureaucrat& bure);
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);