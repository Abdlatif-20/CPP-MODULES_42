/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:31:06 by aben-nei          #+#    #+#             */
/*   Updated: 2023/10/09 18:49:23 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     nbContacts;
    public:
        std::string GetContact(int index);
        int    getNbContacts();
        void        SetContact(int index);
        void    addContact(int index);
        void    searchContact();
        void    setNumber(int index);
};

#endif