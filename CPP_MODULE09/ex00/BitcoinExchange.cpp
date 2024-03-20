/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:28:32 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/20 01:26:15 by aben-nei         ###   ########.fr       */
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
	if (line == header)
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

static float	stringToFloat(const std::string& str)
{
	std::istringstream iss(str);
	float result;
	iss >> result;
	return result;
}

static bool	checkValue(const std::string& value)
{
	int flagPoint = 0;
	// for to check value is valid
	for (size_t i = 0; i < value.length(); i++)
	{
		if (i == 0 && value[i] == '+')
			continue ;
		if (value[i] == '.' || value[i] == '0')
		{
			value[i] == '.' ? flagPoint++ : flagPoint;
			if (flagPoint > 1 || (flagPoint && value.length() == 1))
				return (std::cout << "Error: invalid value" << std::endl, false);
			continue ;
		}
		if (i == 0 && value[i] == '-')
			throw std::invalid_argument("Error: not a positive number");
		if (!std::isdigit(value[i]) && value[0] != '-')
			return (std::cout << "Error: invalid value" << std::endl, false);
	}
	float valueLong = stringToFloat(value);
	if (valueLong > 1000)
		return (std::cout << "Error: too large a number" << std::endl, false);
	if (valueLong < 0)
		return (std::cout << "Error: not a positive number" << std::endl, false);
	return true;
}

static int stringToInt(const std::string& str)
{
	std::istringstream iss(str);
	int result;
	iss >> result;
	return result;
}


bool	checkDate(const std::string& year, const std::string& month, const std::string& day)
{
	if (day.length() > 2 || month.length() > 2 || year.length() != 4)// check length
		return (std::cout << "Error: invalid date" << std::endl, false);
	if (stringToInt(year) < 2005 || stringToInt(year) > 2024) // check year
		return (std::cout << "Error: invalid year" << std::endl, false);
	if (stringToInt(month) < 1 || stringToInt(month) > 12) // check month
		return (std::cout << "Error: invalid month" << std::endl, false);
	if (stringToInt(day) < 1 || stringToInt(day) > 31) // check day 
		return (std::cout << "Error: invalid day" << std::endl, false);
	if (isLeapYear(stringToInt(year)) && stringToInt(month) == 2 && stringToInt(day) > 29) // check leap year
		return (std::cout << "Error: invalid day" << std::endl, false);
	if (!isLeapYear(stringToInt(year)) && stringToInt(month) == 2 && stringToInt(day) > 28) // check leap year
		return (std::cout << "Error: invalid day" << std::endl, false);
	return true;
}

void	BitcoinExchange::parseInsertData(const std::string& year, const std::string& month, const std::string& day, const std::string& value)
{
	BitcoinExchange::currencies.insert(std::pair<Date, float>(Date(stringToInt(day),
		stringToInt(month), stringToInt(year)), stringToFloat(value)));
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

void BitcoinExchange::readyToExchange(std::vector<std::string> date, std::string value)
{
	std::string day = trim(date[2]);
	std::string month = trim(date[1]);
	std::string year = trim(date[0]);
	Date searchDate(stringToInt(day), stringToInt(month), stringToInt(year));
	// Find the exact or nearest lower date
	std::map<Date, float>::iterator it = currencies.lower_bound(searchDate);
	if (it != currencies.end() && it->first != searchDate && it == currencies.begin()) {
		std::cout << "No data available for the provided date or earlier." << std::endl;
		return ;
	}
	else if (it != currencies.begin() && it != currencies.end() && it->first != searchDate) {
		--it; // Move iterator to nearest lower date
	}
	// Calculate result
	double result;
	if (it != currencies.end())
	{
		result = it->second * stringToFloat(value);
		std::cout <<year << "-" << month << "-" << day << " => " << value << " = " << result << std::endl;
	}
	else {
		std::cout << "No data available for the provided date or earlier." << std::endl;
	}
}

void	BitcoinExchange::fillData(const char *input)
{
	if (!input)
		throw std::invalid_argument("Error: invalid Argument");
	std::ifstream infile(input);
	std::string line;

	if (!infile.is_open())
		throw std::invalid_argument("Error: could not open file.");
	std::getline(infile, line);
	for (;std::getline(infile, line);)
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw std::invalid_argument("Error: invalid format");
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1, line.length());
		std::vector <std::string> dateSplit = customSplit(date, '-'); // split(date, '-');
		parseInsertData(trim(dateSplit[0]), trim(dateSplit[1]), trim(dateSplit[2]), trim(value));
	}
	infile.close();
}

void	BitcoinExchange::btcExchange(const char *input, const char *data)
{
	if (!input || !data)
		throw std::invalid_argument("Error: invalid Argument");
	fillData(data);
	std::ifstream infile(input);
	std::string line;

	if (!infile.is_open())
		throw std::invalid_argument("Error: could not open file.");
	std::getline(infile, line);
	if (line.empty())
		throw std::invalid_argument("Error: Empty file");
	if (!checkHeader(line))
		throw std::invalid_argument("Error: invalid header");
	std::string header = "date | value";
	if(!infile.eof())
		std::cout << header << std::endl;
	for (;std::getline(infile, line);)
	{
		if (line.empty())
		{
			std::cout << "Error: invalid line" << std::endl;
			continue ;
		}
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: invalid line(missing `|`)" << std::endl;
			continue ;
		}
		std::string date = line.substr(0, pos);
		std::string value = trim(line.substr(pos + 1, line.length()));
		if (date.empty() || value.empty())
		{
			std::cout << "Error: invalid line" << std::endl;
			continue ;
		}
		if (!checkValue(value))
			continue ;
		std::vector <std::string> dateSplit = customSplit(date, '-'); // split(date, '-');
		if (!checkDate(trim(dateSplit[0]), trim(dateSplit[1]), trim(dateSplit[2])))
			continue ;
		readyToExchange(dateSplit, value);
	}
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

bool Date::operator==(const Date& other) const
{
	return (this->year == other.year && this->month == other.month && this->day == other.day);
}

bool Date::operator!=(const Date& other) const
{
	return !(*this == other);
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
