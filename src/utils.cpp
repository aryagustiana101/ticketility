#include <ctime>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "headers/data.h"

using namespace std;

string generateCode(int length)
{
  string result;
  const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0; i < length; ++i)
  {
    int randomIndex = rand() % (sizeof(alphabet) - 1);
    result += *(alphabet + randomIndex);
  }

  return result;
}
