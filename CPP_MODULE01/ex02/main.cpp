/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:37:33 by aben-nei          #+#    #+#             */
/*   Updated: 2023/10/18 01:48:44 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout<<"address of str: "<<&str<<std::endl;
    std::cout<<"address of ptr: "<<stringPTR<<std::endl;
    std::cout<<"address of ref: "<<&stringREF<<std::endl;


    std::cout<<"value: "<<str<<std::endl;
    std::cout<<"value pointed by ptr: "<<*stringPTR<<std::endl;
    std::cout<<"value pointed by ref: "<<stringREF<<std::endl;
}