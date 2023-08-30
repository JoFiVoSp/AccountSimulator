#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>

struct Account
{
	std::string Email;
	std::string password;
	std::string customernumber;
};

bool operator==(const Account& first, const Account& second);

void createAccount(std::vector<Account>& accounts);

bool LogIn(std::vector<Account>& accounts);

void saveAccount(std::vector<Account>& accounts);

void loadAccounts(std::vector<Account>& accounts);

#endif //!CREATEACCOUNT_H
