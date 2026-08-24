#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


void    Account::_displayTimestamp( void )
{
    time_t rawtime;
    time(&rawtime);
    struct tm *timeinfo;
    timeinfo = localtime(&rawtime);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "] ";
}

Account::Account(int initial_deposit)
{
    static int i = 0;

    _accountIndex = i;
    _amount = initial_deposit;
    _displayTimestamp();
    std::cout <<"index:"<< _accountIndex <<";amount:"<< _amount <<";created\n";
    _nbAccounts = i + 1;
    _totalAmount += _amount;
    i++;
}


void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" 
    << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;

}

void	Account::makeDeposit(int deposit)
{
    static int i = 0;
    _accountIndex = i;
    _nbDeposits = deposit;
    int p_amount = _amount;
    _amount = _amount + deposit;
    if (deposit > 0)
    {
        _totalNbDeposits++;
        _nbDeposits = 1;
    }
    else
        _nbDeposits = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" 
    << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    _totalAmount += deposit;
    i++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    static int i = 0;
    _accountIndex = i;
    _nbWithdrawals = withdrawal;
    int p_amount = _amount;
    if (_nbWithdrawals > 0 && _amount >= _nbWithdrawals)
    {
        _amount = _amount - _nbWithdrawals;
        _totalNbWithdrawals++;
        _nbWithdrawals = 1;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" 
        << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        _totalAmount -= withdrawal;
    }
    else
    {
        _nbWithdrawals = 0;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused\n";
    }
    i++;
    return (0);
}

void Account::displayStatus( void ) const
{
    static int i = 0;
    if(i == 8)
        i = 0;
    _displayTimestamp();
    std::cout << "index:" << i << ";amount:" 
    << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
    i++;
}



Account::~Account()
{
    static int i = 0;

    _accountIndex = i;
    _displayTimestamp();
    std::cout <<"index:"<< _accountIndex <<";amount:"<< _amount <<";closed\n";
    i++;
}