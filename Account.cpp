#include "Account.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Utils.h"



using namespace std;


bool operator==(const Account& first, const Account& second)
{
	return (
		first.Email == second.Email &&
		first.customernumber == second.customernumber &&
		first.password == second.password
		);
}




string createCustomerNumber()
{
	// Customer numbers: 2 numbers, 4 letters
	const int length = 6;

	string customerNumber(length, ' ');
	for (int i = 0; i < length; i++)
	{
		if (i < 2)
			customerNumber[i] = GetRandomInt();
		else
			customerNumber[i] = GetRandomChar();
	}
	return customerNumber;
}






void createAccount(vector<Account>& accounts)
{
	// use sleep function to simulate loading (three dots)
	cout << "Creating Account .";
	wait(1);
	cout << ".";
	wait(1);
	cout << "." << endl << endl;


	bool isEmail = false;
	string email;
	do
	{
		cout << "Email: ";
		cin >> email;
		if (email.find('@') != (size_t)-1 && email.find('.') != (size_t)-1)
			isEmail = true;
		else
			cout << "Email is incorrect!" << endl;
	} while (!isEmail);

	bool isViablePassword = false;
	string password;
	do
	{
		password.clear();
		cout << "Password: ";
		cin >> password;
		if (password.length() < 8)
			cout << "\033[31m" << "Your password must have at least 8 signs!" "\033[0m" << endl;
		else if (containsNumber(password) == false)
			cout << "\033[31m" << "Your password must have at least one number!" "\033[0m" << endl;
		else if (containsUppercase(password) == false)
			cout << "\033[31m" << "Your password must have at least one uppercase letter!" "\033[0m" << endl;
		else
			isViablePassword = true;

	} while (!isViablePassword);

	string customerNumber = createCustomerNumber();
	cout << "costumernumber: " << customerNumber << endl;


	accounts.push_back({ email, password, customerNumber });
	saveAccount(accounts);
}



bool LogIn(vector<Account>& accounts)
{
	Account UserInput;
	cout << "Email: ";
	cin >> UserInput.Email;
	cout << endl << "Password: ";
	cin >> UserInput.password;
	cout << endl << "Costumernumber: ";
	cin >> UserInput.customernumber;

	for (Account account : accounts)
		if (account == UserInput)
			return true;

	return false;
}

void saveAccount(vector<Account>& accounts)
{
	ofstream file;
	file.open("Accounts.txt", ios::app);
	if (file.is_open()) {
			file << accounts.back().Email << "\n"
				<< accounts.back().password << "\n"
				<< accounts.back().customernumber << "\n";
		file.close();
	}
	else {
		cout << "Error: couldnt open file 'Accounts.txt'";
		exit(1);
	}
}

void loadAccounts(vector<Account>& accounts)
{
	int nLines = lineCount("Accounts.txt");

	ifstream file;
	file.open("Accounts.txt");
	if (file.is_open()) {
		for (int i = 0; i < nLines; i++) {
			Account account;

			getline(file, account.Email);
			getline(file, account.password);
			getline(file, account.customernumber);
			
			accounts.push_back(account);
		}
		file.close();
	}
	else{
		cout << "Error: couldnt open file 'Accounts.txt'";
		exit(1);
	}
}

