/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:17:53 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/12 14:42:54 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./eval_expr \"[expression]\"" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.parse(av[1]);
    return 0;
}
