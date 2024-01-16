/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:43:34 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/14 22:42:23 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include"Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;

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
		Bureaucrat();
		Bureaucrat(const std::string& name, const unsigned int& grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();

		const std::string &getName() const;
		const unsigned int &getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);