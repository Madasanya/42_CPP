/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:40:09 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/05 00:40:09 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created"<< std::endl;
	_nbAccounts++;
	_totalAmount = _totalAmount + this->_amount;
	return ;
}

Account::Account( void )
{
	std::cout << "void acc" << std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	if (this->_accountIndex == this->_nbAccounts - 1)
		std::cout << ";amount:" << this->_amount << ";closed";
	else
		std::cout << ";amount:" << this->_amount << ";closed"<< std::endl;
	return ;
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return;
}

void Account::makeDeposit( int deposit )
{
	int p_amount = this->_amount;
	this->_nbDeposits++;
	this->_amount += deposit; 
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << p_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	_totalNbDeposits++;
	return;
}

bool Account::makeWithdrawal( int withdrawal )
{
	int p_amount = this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << p_amount;

	if(this->checkAmount() >= withdrawal)
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal; 
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	else
		std::cout << ";withdrawal:refused" << std::endl;
	return 1;
}

int Account::checkAmount( void ) const
{
	return (this->_amount);
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
	std::time_t rawtime;
	std::tm* timeinfo;
	char buffer [80];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);

	std::strftime(buffer,80,"[%Y%m%d_%H%M%S] ",timeinfo);
	std::cout << (buffer);

	return;
}