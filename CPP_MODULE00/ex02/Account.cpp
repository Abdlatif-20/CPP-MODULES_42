/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:49:26 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/08 15:04:29 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<"accounts:"<<_nbAccounts;
	std::cout<<";total:"<<_totalAmount;
	std::cout<<";deposits:"<<_totalNbDeposits;
	std::cout<<";withdrawals:"<<_totalNbWithdrawals;
	std::cout<<std::endl;
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";amount:"<<_amount;
	std::cout<<";created"<<std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";amount:"<<_amount;
	std::cout<<";closed"<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit < 0)
		return ;
	_nbDeposits++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";p_amount:"<<_amount;
	std::cout<<";deposit:"<<deposit;
	std::cout<<";amount:"<<_amount + deposit;
	std::cout<<";nb_deposits:"<<_nbDeposits;
	std::cout<<std::endl;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout<<"index:"<<_accountIndex;
		std::cout<<";p_amount:"<<_amount;
		std::cout<<";withdrawal:refused"<<std::endl;
		return (false);	
	}
	_nbWithdrawals++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";p_amount:"<<_amount;
	std::cout<<";withdrawal:"<<withdrawal;
	std::cout<<";amount:"<<_amount - withdrawal;
	std::cout<<";nb_withdrawals:"<<_nbWithdrawals;
	std::cout<<std::endl;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex;
	std::cout<<";amount:"<<_amount;
	std::cout<<";deposits:"<<_nbDeposits;
	std::cout<<";withdrawals:"<<_nbWithdrawals;
	std::cout<<std::endl;
}

void	Account::_displayTimestamp( void )
{
	tm		*info;
	time_t	_epoch;
	char	line[256];

	std::time(&_epoch);
	info = std::localtime(&_epoch);
	std::strftime(line, 256, "[%Y%m%d_%H%M%S] ", info);
	std::cout << line;
}
