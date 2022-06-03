/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:33:48 by ryesenia          #+#    #+#             */
/*   Updated: 2022/06/03 21:33:54 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Account.hpp"
# include <iomanip>
# include <chrono>

	int Account :: _nbAccounts = 0;
	int Account :: _totalAmount = 0;
	int Account :: _totalNbDeposits = 0;
	int Account :: _totalNbWithdrawals = 0;
	
	Account::~Account()
	{
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "closed" << std::endl;
		}
	Account::Account(){}  // пустой конструктор! 

	int		Account::getNbAccounts( void )
	{
		return (_nbAccounts);
	}
	int		Account::getTotalAmount( void )
	{
		return(_totalAmount);
	}
	int		Account::getNbDeposits( void )
	{
		return (_totalNbDeposits);
	}
	int		Account::getNbWithdrawals( void )
	{
		return (_totalNbWithdrawals);
	}
	void	Account::displayAccountsInfos( void )
	{
		Account::_displayTimestamp();
		std::cout << "accounts:" << getNbAccounts() << ";";
		std::cout << "total:" << getTotalAmount() << ";";
		std::cout << "deposits:" << getNbDeposits() << ";";
		std::cout << "withdrawls:" << getNbWithdrawals() << ";" << std::endl;
	}

	Account::Account( int initial_deposit )
	{
		_accountIndex = _nbAccounts;
		_totalAmount += initial_deposit;
		_amount = initial_deposit;
		_nbAccounts ++;
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "p_amount:" << _accountIndex << ";";
		std::cout << "created:" << std::endl;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
	}

void Account::_displayTimestamp(void)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	tm utc_tm = *localtime(&time_now);
	std::cout << std::setfill('0') << "[" << (utc_tm.tm_year + 1900)
			<< std::setw(2) << utc_tm.tm_mon
			<< std::setw(2) << utc_tm.tm_mday << "_"
			<< std::setw(2) << utc_tm.tm_hour
			<< std::setw(2) << utc_tm.tm_min
			<< std::setw(2) << utc_tm.tm_sec << "] ";
	//std::cout << "[19920104_091532] ";
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "deposit:" << _nbDeposits << ";";
		std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}

int		Account::checkAmount( void ) const
{
	displayStatus();
	
	return(_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	
	if (withdrawal > _amount)
	{
		std::cout << "withdrawl:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawl:" << withdrawal << ";";	
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << ";" << std::endl;
	_totalNbWithdrawals += 1;
	return (true);
	
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		_amount += deposit;
		std::cout << "deposit:" << deposit << ";";
		std::cout << "amount:" << _amount  << ";";
		_nbDeposits += 1;
		std::cout << "nb_deposit:" << _nbDeposits << ";" << std::endl;
		_totalNbDeposits += 1;
		_totalAmount += deposit;
}
