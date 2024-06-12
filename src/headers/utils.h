#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

string generateCode(int length);
string randomItem(vector<string> items);
string getCurrentDateTime();
void setStdinEcho(bool enable);
string inputPassword();
void clearScreen();

#endif
