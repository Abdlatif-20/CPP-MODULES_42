/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:47:25 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/10 01:35:57 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
    std::string		firstName;
    std::string		lastName;
    std::string		nickname;
    std::string		phoneNumber;
    std::string		darkestSecret;
public:
    void			setFirstName(std::string firstName);
    void			setLastName(std::string lastName);
    void			setNickname(std::string nickname);
    void			setPhoneNumber(std::string phoneNumber);
    void			setDarkestSecret(std::string darkestSecret);
    std::string		getFirstName();
    std::string		getLastName();
    std::string		getNickname();
    std::string		getPhoneNumber();
    std::string		getDarkestSecret();
};

bool	check_PhoneNumber(std::string phoneNumber);

#endif