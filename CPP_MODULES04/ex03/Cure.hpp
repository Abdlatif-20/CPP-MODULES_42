/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:15:23 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/08 21:48:50 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include"AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& obj);
		Cure& operator=(const Cure& obj);
		~Cure();

		AMateria *clone() const;
		void use(ICharacter &target);
};