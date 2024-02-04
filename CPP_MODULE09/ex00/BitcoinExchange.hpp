/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:28:29 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/27 03:54:32 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

class Date
{
	private:
		int day;
		int month;
		int year;
		Date();
	public:
		Date(int day, int month, int year);
		void	setDay(int day);
		void	setMonth(int month);
		void	setYear(int year);
		int		getDay() const;
		int		getMonth() const;
		int		getYear() const;
		bool	operator<(const Date& obj) const;
		~Date();
};

class BitcoinExchange
{
	private:
		static std::map<Date, float> currencies;
		BitcoinExchange();
	public:
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange();
		static void	btcExchange(const char *input, const char *data);
		static void	parseInsertData(const std::string& year, const std::string& month, const std::string& day, const std::string& value);
		static void	readyToExchange(const char *data);
};
