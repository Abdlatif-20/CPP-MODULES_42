/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:53:26 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/22 13:20:38 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include"iostream"

class Weapon{
	private:
		std::string type;
	public:
		const std::string& getType() const;
		void	setType(const std::string& type);
		Weapon(const std::string& type);
		Weapon();
};

#endif