/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:53:26 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/21 10:11:44 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include"iostream"

class Weapon{
	private:
		std::string type;
	public:
		std::string getType()const;
		void	setType(std::string type);
		Weapon(std::string type);
		Weapon();
};

#endif