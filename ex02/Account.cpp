/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:04:47 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/05 16:52:58 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


/* ************************************************************************** */
/* ************************************************************************** */


Account::Account( void )
{
	_accountIndex = _nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "created" << std::endl;	
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "created" << std::endl;	
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "closed" << std::endl;
}


/* ************************************************************************** */
/* ************************************************************************** */


int	Account::getNbAccounts( void )
{
	return ( _nbAccounts );
}

int	Account::getTotalAmount( void )
{
	return ( _totalAmount );
}

int	Account::getNbDeposits( void )
{
	return ( _totalNbDeposits );
}

int	Account::getNbWithdrawals( void )
{
	return ( _totalNbWithdrawals );
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
	<< "total:" << _totalAmount << ";"
	<< "deposits:" << _totalNbDeposits << ";"
	<< "withdrawals:" << _totalNbWithdrawals
	<< std::endl;	
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Account::makeDeposit( int deposit )
{
	int	p_amount;
	
	p_amount = _amount;
	
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << _amount << ";"
	<< "nb_deposits:" << _nbDeposits
	<< std::endl;	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount;
	
	p_amount = _amount;
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;

		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;	
		return ( true );
	}

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "withdrawal:refused"
	<< std::endl;
	return ( false );
}

int		Account::checkAmount( void ) const
{
	return ( _amount );
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals
	<< std::endl;	
	return ;
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Account::_displayTimestamp( void )
{
	time_t ct;
	std::tm *lt;

	time(&ct);
	lt = std::localtime(&ct);
	std::cout	<< "["
				<< lt->tm_year + 1900
				<< std::setw(2) << std::setfill('0') << lt->tm_mon
				<< std::setw(2) << std::setfill('0') << lt->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << lt->tm_hour
				<< std::setw(2) << std::setfill('0') << lt->tm_min
				<< std::setw(2) << std::setfill('0') << lt->tm_sec
				<< "] ";
}
