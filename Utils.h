#ifndef UTILS_H
#define UTILS_H

#include <iostream>

int GetRandomInt();
char GetRandomChar();

bool containsNumber(std::string string);

bool containsUppercase(std::string string);

void wait(int length);

int lineCount(const std::string& fileName);

void createFile(const std::string& fileName);

#endif // UTILS_H
