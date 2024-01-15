/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:14:17 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/15 22:12:40 by aben-nei         ###   ########.fr       */
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		AForm();
		AForm(const std::string& target, const unsigned int& gradeSign, const unsigned int& gradeExecute);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual	~AForm();

		const std::string&	getName() const;
		const bool&			isSign() const;
		const unsigned int&	getGradeSign() const;
		const unsigned int&	getGradeExecute() const;
		void				beSigned(Bureaucrat& bure);
		virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);