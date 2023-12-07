/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:47:49 by aben-nei          #+#    #+#             */
/*   Updated: 2023/11/11 17:52:54 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	string_name;
	public:
		Zombie();
		~Zombie();
		void	announce();
		void	setName(std::string name);
		std::string	getNmae();
};
void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif