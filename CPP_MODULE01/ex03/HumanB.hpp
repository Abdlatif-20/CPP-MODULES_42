/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:03:24 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/22 13:32:16 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include<iostream>
#include"Weapon.hpp"

class HumanB{
	private:
		std::string name;
		Weapon *weapon;
	public:
		void	attack();
		HumanB(std::string name);
		HumanB();
		void	setWeapon(Weapon& weapon);
		
};

#endif