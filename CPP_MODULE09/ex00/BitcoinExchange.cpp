/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:28:32 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/27 06:16:52 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<Date, float> BitcoinExchange::currencies;

#pragma region Canonical
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	(void)obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	(void)obj;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}
#pragma endregion Canonical

static bool	checkHeader(std::string line)
{
	std::string header = "date | value";
	if (!line.compare(header))
		return true;
	return false;
}

// Function to trim spaces from the beginning and end of a string
static std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

static bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	} else {
		return false;
	}
}

static void	checkValue(const std::string& value)
{
	int flagPoint = 0;
	if (value.length() > 10)
		throw std::invalid_argument("Error: invalid value");
	// for to check value is valid
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.' || value[i] == '0')
		{
			value[i] == '.' ? flagPoint++ : flagPoint;
			if (flagPoint > 1)
				throw std::invalid_argument("Error: invalid value");
			continue ;
		}
		if (!std::isdigit(value[i]))
			throw std::invalid_argument("Error: invalid value");
	}
	long valueLong = std::atol(value.c_str());
	if (valueLong > 2147483647 || valueLong < -2147483648)
		throw std::out_of_range("Error: too large a numbe");
}

void	BitcoinExchange::parseInsertData(const std::string& year, const std::string& month, const std::string& day, const std::string& value)
{
	if (day.length() != 2 || month.length() != 2 || year.length() != 4)// check length
		throw std::invalid_argument("Error: invalid value");
	if (std::stoi(day) < 1 || std::stoi(day) > 31) // check day 
		throw std::invalid_argument("Error: invalid value");
	if (std::stoi(month) < 1 || std::stoi(month) > 12) // check month
		throw std::invalid_argument("Error: invalid value");
	if (std::stoi(year) < 2005 || std::stoi(year) > 2024) // check year
		throw std::invalid_argument("Error: invalid value");
	if (isLeapYear(std::stoi(year)) && std::stoi(month) == 2 && std::stoi(day) > 29) // check leap year
		throw std::invalid_argument("Error: invalid value");
	checkValue(value);
	BitcoinExchange::currencies.insert(std::pair<Date, float>(Date(std::stoi(day), std::stoi(month), std::stoi(year)), std::stof(value)));
}

std::vector<std::string> customSplit(const std::string& str, char delim)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);
	while (std::getline(tokenStream, token, delim))
		tokens.push_back(token);
	return tokens;
}

void	printfMap(std::map<Date, float> currencies)
{
	for (std::map<Date, float>::iterator it = currencies.begin(); it != currencies.end(); ++it)
		std::cout <<"year: " << it->first.getYear() << " month: " << it->first.getMonth() << " day: " << it->first.getDay() << " value: " << it->second << std::endl;
}

void	BitcoinExchange::readyToExchange(const char *data)
{
	if (!data)
		throw std::invalid_argument("Error: invalid value");
	std::ifstream infile(data);
	std::string line;
	if (!infile.is_open())
		throw std::invalid_argument("Error: invalid value");
	std::getline(infile, line);
	if (!checkHeader(line))
		throw std::invalid_argument("Error: invalid value");
	
	infile.close();
}

void	BitcoinExchange::btcExchange(const char *input, const char *data)
{
	if (!input || !data)
		throw std::invalid_argument("Error: invalid value");
	std::ifstream infile(input);
	std::string line;

	if (!infile.is_open())
		throw std::invalid_argument("Error: could not open file.");
	std::getline(infile, line);
	if (!checkHeader(line))
		throw std::invalid_argument("Error: invalid value");
	for (;std::getline(infile, line);)
	{
		if (line.empty())
			throw std::invalid_argument("Error: invalid value");
		size_t pos = line.find('|');
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1, line.length());
		std::vector <std::string> dateSplit = customSplit(date, '-'); // split(date, '-');
		parseInsertData(trim(dateSplit[0]), trim(dateSplit[1]), trim(dateSplit[2]), trim(value));
	}
	// readyToExchange(data);
	// printfMap(currencies);
	infile.close();
}


#pragma region Date

void	Date::setDay(int day)
{
	this->day = day;
}

void	Date::setMonth(int month)
{
	this->month = month;
}

void	Date::setYear(int year)
{
	this->year = year;
}

int		Date::getDay() const
{
	return this->day;
}

int		Date::getMonth() const
{
	return this->month;
}

int		Date::getYear() const
{
	return this->year;
}

bool	Date::operator<(const Date& obj) const
{
	if (this->year < obj.year)
		return true;
	else if (this->year == obj.year)
	{
		if (this->month < obj.month)
			return true;
		else if (this->month == obj.month)
		{
			if (this->day < obj.day)
				return true;
		}
	}
	return false;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date()
{
}

Date::~Date()
{
}
#pragma endregion Date
