/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:20:07 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/22 02:42:58 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include<iostream>

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
		void (Harl::*ptr[4])();
	public:
		Harl();
		void complain(std::string level);
		
};

#endif