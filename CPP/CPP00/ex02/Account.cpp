#include "Account.hpp"
#include <iostream>
#include <iomanip>

int		Account::checkAmount( void ) const{
	return Account::_amount;
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount <<";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbDeposits << ";";
}

void 	Account::_displayTimestamp(void){
	std::time_t time;
	std::tm *ptm = std::localtime(&time);
	std::cout << std::put_time(ptm, "[%y%m%d_%H%M%S] ");
}

int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}
int	Account::getTotalAmount( void ){
	return Account::_totalAmount;
}
int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void ){
	std::cout << _displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << ";";
	std::cout << std::endl;
}

Account::Account(int initial_deposit){
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount <<";";
	std::cout << "created";
	std::cout << std::endl;
	Account::_nbAccounts++;
}

Account::~Account(void){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount <<";";
	std::cout << "closed";
	Account::_nbAccounts--;
}


void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";" ;

	this->_amount += deposit;
	this->_nbDeposits += 1;

	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposit:" << this->_nbDeposits << ";";
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";" ;

	if (this->_amount - withdrawal < 0){
		std::cout << "withdrawal:refused" << std::endl;
	}
	else{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";";
		std::cout << std::endl;
	}
}

