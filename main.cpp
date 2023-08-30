#include <iostream>
#include "Account.h"
#include "Utils.h"


using namespace std;


vector<Account> accounts;

// the goal of this project is to show my current programming skills, so this may not be the shortest variant possible
// and this is just a simulation so its not secure or using any APIs
// note: I coded everything by myself, but used chatgpt as a debugger (i did not blindly copy amd paste)


int main()
{
	createFile("Accounts.txt");
	loadAccounts(accounts);

	char input;
	while (true)
	{
		cout << "Log in [L] Sign up [S]" << endl;
		cin >> input;

		if (toupper(input) == 'S')
		{
			createAccount(accounts);
			cout << "Account created!" << endl;
		}
		else if (toupper(input) == 'L')
		{
			if (LogIn(accounts) == true)
			{

				cout << "Logged in succesfully!" << endl;
				return 0;
			}
			else
				cout << "Incorrect!" << endl;
		}
		else
		{
			cout << "Your Input wasnt correct! Try [L] to log in or [S] to sign up!" << endl;
		}
	}

	return 0;
}