/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:07:25 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/19 00:13:56 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Base
{
	public:
		virtual ~Base();
};

/* ************** Functions ******************** */

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);