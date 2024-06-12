#include <ctime>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <termios.h>
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

string randomItem(vector<string> items)
{
  return items[rand() % items.size()];
}

string getCurrentDateTime()
{
  auto now = chrono::system_clock::now();

  time_t now_time_t = chrono::system_clock::to_time_t(now);

  tm now_tm;

#ifdef _WIN32
  gmtime_s(&now_tm, &now_time_t);
#else
  gmtime_r(&now_time_t, &now_tm);
#endif

  stringstream ss;
  ss << put_time(&now_tm, "%Y-%m-%dT%H:%M:%S");

  auto now_time_point = chrono::system_clock::now();
  time_t local_time_t = chrono::system_clock::to_time_t(now_time_point);

  tm local_tm;
#ifdef _WIN32
  localtime_s(&local_tm, &local_time_t);
#else
  localtime_r(&local_time_t, &local_tm);
#endif

  return ss.str();
}

void setStdinEcho(bool enable)
{
  struct termios tty;
  tcgetattr(STDIN_FILENO, &tty);
  if (!enable)
    tty.c_lflag &= ~ECHO;
  else
    tty.c_lflag |= ECHO;

  (void)tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

string inputPassword()
{
  char ch;
  string password;

  setStdinEcho(false);

  cout << "Enter password: ";
  while (cin.get(ch) && ch != '\n')
  {
    if (ch == 127 || ch == 8)
    {
      if (!password.empty())
      {
        cout << "\b \b";
        password.pop_back();
      }
    }
    else
    {
      cout << '*';
      password += ch;
    }
  }

  setStdinEcho(true);

  cout << endl;

  return password;
}