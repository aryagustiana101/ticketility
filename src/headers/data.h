#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

using namespace std;

enum UserType
{
  ADMIN,
  REGULAR
};

struct User
{
  string username;
  string password;
  UserType type;
};

#endif