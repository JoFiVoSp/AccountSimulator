#include "Utils.h"
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std;

int GetRandomInt()
{
	random_device randomDevice;
	mt19937 randomGenerator(randomDevice());

	uniform_int_distribution<int> dis(48, 57);

	int randomNumber = dis(randomGenerator);

	return randomNumber;
}

char GetRandomChar()
{
	random_device randomDevice;
	mt19937 randomGenerator(randomDevice());

	uniform_int_distribution<int> dis('a', 'z');

	char randomLetter = dis(randomGenerator);

	return randomLetter;
}


bool containsNumber(string string)
{

	for (int i = 0; i < 10; i++)
	{
		char number = '0' + i;
		if (string.find(number) != (size_t)-1)
			return true;


	}
	return false;
}

bool containsUppercase(string string)
{

	for (int i = 0; i < string.length(); i++)
	{
		if (isupper(string[i]))
			return true;


	}
	return false;
}

void wait(int length)
{
	this_thread::sleep_for(chrono::seconds(length));
}

int lineCount(const string& fileName)
{
	ifstream file;
	int count = 0;
	file.open(fileName);
	if (file.is_open()){
		string temp;
		while (getline(file, temp))
			count++;
		file.close();
	}
	else {
		cout << "Error: couldnt open file '" << fileName << "'!";
		exit(1);
	}

	return count;
}

void createFile(const string& fileName)
{
	ofstream file;
	file.open(fileName, ios::app);
	if (file.is_open())
		file.close();
	else {
		cout << "Error: couldnt create or open the file: '" << fileName << "'!";
		exit(1);
	}
}
