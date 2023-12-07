/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:52:26 by aben-nei          #+#    #+#             */
/*   Updated: 2023/11/13 23:02:09 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include<iostream>
#include"Weapon.hpp"

class HumanA{
	private:
		std::string name;
		Weapon weapon;
	public:
		void	attack();
		HumanA(std::string name, Weapon weapon);
};

#endif