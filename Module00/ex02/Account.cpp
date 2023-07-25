#include "Account.hpp"
#include <iostream>

#define DAY "[19920104_091532] "
#define ACCOUNT "accounts:"
#define TOTAL ";total:"
#define DEPOSIT ";deposit:"
#define DEPOSITS ";deposits:"
#define NB_DEPOSITS ";nb_deposits:"
#define WITHDRAWALS ";withdrawals:"
#define NB_WITHDRAWALS ";nb_withdrawals:"
#define WITHDRAWAL ";withdrawal:"
#define WITHDRAWAL_REFUSED ";withdrawal:refused"
#define INDEX "index:"
#define AMOUNT ";amount:"
#define P_AMOUNT ";p_amount:"
#define CREATED ";created"
#define CLOSED ";closed"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit) {
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << INDEX << _accountIndex << AMOUNT << _amount << CREATED << std::endl;
}

Account::~Account(void) {
    _nbAccounts--;
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout << INDEX << _accountIndex << AMOUNT << _amount << CLOSED << std::endl;
}

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << ACCOUNT << getNbAccounts() << TOTAL << getTotalAmount() \
        << DEPOSITS << getNbDeposits() << WITHDRAWALS << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << INDEX << _accountIndex << AMOUNT << _amount << DEPOSITS << _nbDeposits \
        << WITHDRAWALS << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << INDEX << _accountIndex << P_AMOUNT << _amount - deposit << DEPOSIT << deposit \
        << AMOUNT << _amount << NB_DEPOSITS << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > _amount) {
        _displayTimestamp();
        std::cout << INDEX << _accountIndex << P_AMOUNT \
            << _amount << WITHDRAWAL_REFUSED << std::endl;
        return false;
    } else {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _displayTimestamp();
        std::cout << INDEX << _accountIndex << P_AMOUNT << _amount + withdrawal << \
            WITHDRAWAL << withdrawal << AMOUNT << _amount << \
                NB_WITHDRAWALS << _nbWithdrawals << std::endl;
        return true;
    }
}

void Account::_displayTimestamp(void) {
    std::cout << DAY;
}

int Account::checkAmount(void) const {
    return _amount;
}
