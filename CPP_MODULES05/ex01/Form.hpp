/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:14:17 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/14 23:20:07 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
		Form();
		Form(std::string name, unsigned int gradeSign, unsigned int gradeExecute);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();

		const std::string &getName() const;
		const bool &isSign() const;
		const unsigned int &getGradeSign() const;
		const unsigned int &getGradeExecute() const;
		void	beSigned(Bureaucrat& bure);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);