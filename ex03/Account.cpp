# include <iostream>
# include "Account.hpp"
# include <iomanip>
# include <chrono>

	int Account :: _nbAccounts = 0;
	int Account :: _totalAmount = 0;
	int Account :: _totalNbDeposits = 0;
	int Account :: _totalNbWithdrawals = 0;
	
	Account::~Account(){}

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

	Account::Account(){}
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

/*void	makeDeposit( int deposit )
{
	Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "deposit:" << _nbDeposits << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}*/

int main()
{

	Account f_w(42);
	Account f_w1(54);
	Account f_w2(957);
	Account f_w3(432);
	Account f_w4(1234);
	Account f_w5(0);
	Account f_w6(754);
	Account f_w7(16576);
	Account::displayAccountsInfos();
	f_w.displayStatus();
	f_w1.displayStatus();
	f_w2.displayStatus();
	f_w3.displayStatus();
	f_w4.displayStatus();
	f_w5.displayStatus();
	f_w6.displayStatus();
	f_w7.displayStatus();
	Account::displayAccountsInfos();
	/*Account f_w(5);
	Account f_w1(765);
	Account f_w2(564);
	Account f_w3(2);
	Account f_w4(87);
	Account f_w5(23);
	Account f_w6(9);
	Account f_w7(20);*/

	return (0);
}