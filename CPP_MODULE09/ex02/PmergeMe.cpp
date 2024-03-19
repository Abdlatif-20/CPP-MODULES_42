/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:49:30 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/19 02:00:09 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_struggler = 0;
	_strugglerDeq = 0;
	_foundStruggler = false;
	_foundStrugglerDeq = false;
}

PmergeMe::~PmergeMe()
{
}

t_vector	PmergeMe::getMainChain() const
{
	return _mainChain;
}

t_deque		PmergeMe::getMainChainDeq() const
{
	return _mainChainDeq;
}

// Function to calculate the nth Jacobsthal number
size_t PmergeMe::jacobsthal() {
	static size_t j1 = 1, j2 = 0;
	size_t res = j1 + 2 * j2;
	j2 = j1;
	j1 = res;
	return res;
}

void PmergeMe::detecteLarge()
{
	for (size_t i = 0; i < _numbers.size(); i++)
	{
		if (_numbers[i].first >= 0 && _numbers[i].first < _numbers[i].second)
		{
			std::pair<int, int> tmp = _numbers[i];
			_numbers[i] = std::make_pair(_numbers[i].second, tmp.first);
		}
	}
}
//function to sort the pair
void PmergeMe::prepareSortPair()
{
	for (size_t i = 0; i < _numbers.size(); i++)
	{
		for (size_t j = 0; j < _numbers.size(); j++)
		{
			if (_numbers[i].first < _numbers[j].first)
			{
				std::pair<int, int> tmp = _numbers[i];
				_numbers[i] = _numbers[j];
				_numbers[j] = tmp;
			}
		}
	}
}

//function to split the string
static std::vector<std::string> split(const std::string& str, const char sep)
{
	std::vector<std::string> result;
	std::string token;
	std::istringstream tokenStream(str);
	while (std::getline(tokenStream, token, sep))
		result.push_back(token);
	return result;
}

void	PmergeMe::createMainChainAndPend()
{
	_mainChain.push_back(_numbers[0].second);
	for (size_t i = 0; i < _numbers.size(); i++)
	{
		_mainChain.push_back(_numbers[i].first);
		_pend.push_back(_numbers[i].second);
	}
}

void	printNumbers(std::vector<std::pair<int, int> > numbers)
{
	std::cout << "------------------\n";
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << "-->|Pair: " << numbers[i].first << "|" << numbers[i].second << std::endl;
	}
}

static int stringToInt(const std::string& str)
{
	std::istringstream iss(str);
	int result;
	iss >> result;
	return result;
}

void	PmergeMe::printNumberVec()
{
	for (size_t i = 0; i < _mainChain.size(); i++)
		std::cout << _mainChain[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printNumberDeq()
{
	for (size_t i = 0; i < _mainChainDeq.size(); i++)
		std::cout << _mainChainDeq[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::checkSign(char *av)
{
	int	detecSign = 0;
	for (size_t i = 0; av[i]; i++)
	{
		if (av[i] == '+' && av[i + 1] == '\0')
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		if (av[i] == '+')
			detecSign++;
		if (detecSign > 1)
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
	}
}

std::string	PmergeMe::takingNumbers(char **av)
{
	std::string str = "";
	size_t pos = 0;
	for (size_t i = 1; av[i]; i++)
	{
		str += av[i];
		pos = str.find_first_not_of("0123456789 +");
		if (pos != std::string::npos)
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		checkSign(av[i]);
		if (av[i + 1])
			str += " ";
	}
	return str;
}

void	PmergeMe::mergeNumbers(size_t jac)
{
	for (;jac;)
	{
		if (_pend[jac] == -1)
			break;
		std::vector<int>::iterator it = std::lower_bound(_mainChain.begin(), _mainChain.end(), _pend[jac]);
		_mainChain.insert(it, _pend[jac]);
		_pend[jac] = -1;
		if (jac > 0)
			jac--;
	}
}

void	PmergeMe::mergeStruggler()
{
	std::vector<int>::iterator it = std::lower_bound(_mainChain.begin(), _mainChain.end(), _struggler);
	_mainChain.insert(it, _struggler);
}

void PmergeMe::sortNumbersVec(const std::string &str)
{
	std::vector<std::string> numbers = split(str, ' ');
	clock_t start = 0, end = 0;
	if (numbers.size() == 1)
	{
		_struggler = stringToInt(numbers[0]);
		_foundStruggler = true;
	}
	else if (numbers.size() > 1)
	{
		size_t size;
		for (size_t i = 0; i < numbers.size(); i+=2)
		{
			if (numbers[i].empty())
				continue;
			if (i + 1 >= numbers.size())
			{
				_struggler = stringToInt(numbers[i]);
				_foundStruggler = true;
				break;
			}
			_numbers.push_back(std::make_pair(stringToInt(numbers[i]), stringToInt(numbers[i + 1])));
		}
		start = clock();
		detecteLarge();
		prepareSortPair();
		createMainChainAndPend();
		size = _pend.size();
		size_t fixSize = size;
		_pend[0] = -1;
		for (;size;)
		{
			size_t jac = jacobsthal();
			jac > 1 ? jac-- : jac;
			if (jac == 1)
				continue;
			if (jac > fixSize)
				jac = fixSize - 1;
			mergeNumbers(jac);
			size--;
		}
	}
	if (_foundStruggler)
		mergeStruggler();
	end = clock();
	double time_taken_vector = double(end - start) / double(CLOCKS_PER_SEC) * 1e6;
	std::cout << "Time to process a range of " << _mainChain.size() <<
		" elements with std::vector: " << time_taken_vector << " us" << std::endl;
}

// sort deque numbers
void PmergeMe::detecteLargeDeq()
{
	for (size_t i = 0; i < _numbersDeque.size(); i++)
	{
		if (_numbersDeque[i].first >= 0 && _numbersDeque[i].first < _numbersDeque[i].second)
		{
			std::pair<int, int> tmp = _numbersDeque[i];
			_numbersDeque[i] = std::make_pair(_numbersDeque[i].second, tmp.first);
		}
	}
}

void PmergeMe::prepareSortPairDeq()
{
	for (size_t i = 0; i < _numbersDeque.size(); i++)
	{
		for (size_t j = 0; j < _numbersDeque.size(); j++)
		{
			if (_numbersDeque[i].first < _numbersDeque[j].first)
			{
				std::pair<int, int> tmp = _numbersDeque[i];
				_numbersDeque[i] = _numbersDeque[j];
				_numbersDeque[j] = tmp;
			}
		}
	}
}

void	PmergeMe::createMainChainAndPendDeq()
{
	_mainChainDeq.push_back(_numbersDeque[0].second);
	for (size_t i = 0; i < _numbersDeque.size(); i++)
	{
		_mainChainDeq.push_back(_numbersDeque[i].first);
		_pendDeq.push_back(_numbersDeque[i].second);
	}
}

void	PmergeMe::mergeNumbersDeq(size_t jac)
{
	for (;jac;)
	{
		if (_pendDeq[jac] == -1)
			break;
		std::deque<int>::iterator it = std::lower_bound(_mainChainDeq.begin(), _mainChainDeq.end(), _pendDeq[jac]);
		_mainChainDeq.insert(it, _pendDeq[jac]);
		_pendDeq[jac] = -1;
		if (jac > 0)
			jac--;
	}
}

void	PmergeMe::mergeStrugglerDeq()
{
	std::deque<int>::iterator it = std::lower_bound(_mainChainDeq.begin(), _mainChainDeq.end(), _strugglerDeq);
	_mainChainDeq.insert(it, _strugglerDeq);
}

void PmergeMe::sortNumbersDeq(const std::string &str)
{
	std::vector<std::string> numbers = split(str, ' ');
	clock_t start = 0, end = 0;
	if (numbers.size() == 1)
	{
		_strugglerDeq = stringToInt(numbers[0]);
		_foundStrugglerDeq = true;
	}
	else if (numbers.size() > 1)
	{
		size_t size;
		for (size_t i = 0; i < numbers.size(); i+=2)
		{
			if (numbers[i].empty())
				continue;
			if (i + 1 >= numbers.size())
			{
				_strugglerDeq = stringToInt(numbers[i]);
				_foundStrugglerDeq = true;
				break;
			}
			_numbersDeque.push_back(std::make_pair(stringToInt(numbers[i]), stringToInt(numbers[i + 1])));
		}
		start = clock();
		detecteLargeDeq();
		prepareSortPairDeq();
		createMainChainAndPendDeq();
		size = _pendDeq.size();
		size_t fixSize = size;
		_pendDeq[0] = -1;
		for (;size;)
		{
			size_t jac = jacobsthal();
			jac > 1 ? jac-- : jac;
			if (jac == 1)
				continue;
			if (jac > fixSize)
				jac = fixSize - 1;
			mergeNumbersDeq(jac);
			size--;
		}
	}
	if (_foundStrugglerDeq)
		mergeStrugglerDeq();
	end = clock();
	double time_taken_deque = double(end - start) / double(CLOCKS_PER_SEC) * 1e6;
	std::cout <<"after: ";
	printNumberDeq();
	std::cout << "Time to process a range of " << _mainChainDeq.size() <<
		" elements with std::deque: " << time_taken_deque << " us" << std::endl;
}
