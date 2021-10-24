/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:38:44 by mchun             #+#    #+#             */
/*   Updated: 2021/10/25 01:26:26 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "index" << ":" << _accountIndex << ";";
	std::cout << "amount" << ":" << _amount << ";";
	std::cout << "created" << std::endl;
}


Account::~Account()
{
	_displayTimestamp();
	std::cout << "index" << ":" << _accountIndex << ";";
	std::cout << "amount" << ":" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts" << ":" << _nbAccounts << ";";
	std::cout << "total" << ":" << _totalAmount << ";";
	std::cout << "deposits" << ":" << _totalNbDeposits << ";";
	std::cout << "withdrawals" << ":" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int		p_amount;

	p_amount = checkAmount();
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;

	_displayTimestamp();
	std::cout << "index" << ":" << _accountIndex << ";";
	std::cout << "p_amount" << ":" << p_amount << ";";
	std::cout << "deposit" << ":" << deposit << ";";
	std::cout << "amount" << ":" << checkAmount() << ";";
	std::cout << "nb_deposits" << ":" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int		p_amount;
	bool	withdraw_refusal;

	if (checkAmount() < withdrawal)
		withdraw_refusal = true;
	else
		withdraw_refusal = false;
	p_amount = checkAmount();
	if (!withdraw_refusal)
	{
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
	}

	_displayTimestamp();
	std::cout << "index" << ":" << _accountIndex << ";";
	std::cout << "p_amount" << ":" << p_amount << ";";
	if (!withdraw_refusal)
	{
		std::cout << "withdrawal" << ":" << withdrawal << ";";
		std::cout << "amount" << ":" << checkAmount() << ";";
		std::cout << "nb_withdrawals" << ":" << _nbWithdrawals;
		std::cout << std::endl;
		return (true);
	}
	else
	{
		std::cout << "withdrawal" << ":" << "refused";
		std::cout << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index" << ":" << _accountIndex << ";";
	std::cout << "amount" << ":" << checkAmount() << ";";
	std::cout << "deposits" << ":" << _nbDeposits<< ";";
	std::cout << "withdrawals" << ":" << _nbWithdrawals;
	std::cout << std::endl;

}

void	Account::_displayTimestamp( void )
{
	time_t		rawtime;
	struct tm	*convertedtime;
	struct tm	*ct;

	time(&rawtime);
	convertedtime = localtime(&rawtime);
	ct = convertedtime;
	std::cout << "[";
	std::cout << ct->tm_year + 1900 << std::setw(2) << std::setfill('0') \
		<< ct->tm_mon + 1 << std::setw(2) << std::setfill('0') \
			<< ct->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << ct->tm_hour \
		<< std::setw(2) << std::setfill('0') << ct->tm_min \
			<< std::setw(2) << std::setfill('0') << ct->tm_sec;
	std::cout << "]";
	std::cout << " ";
}

