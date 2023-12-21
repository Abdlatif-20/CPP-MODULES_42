/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:22:20 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/21 09:36:15 by aben-nei         ###   ########.fr       */
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
Zombie*	zombieHorde( int N, std::string name );

#endif