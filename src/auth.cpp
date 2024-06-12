#include <vector>
#include <string>
#include <iostream>
#include "headers/user.h"
#include "headers/data.h"
#include "headers/utils.h"

using namespace std;

User *login()
{
  vector<User> users = getUsers();

  string username;

  cout << "\nEnter username: ";
  getline(cin, username);

  string password = inputPassword();

  for (auto &user : users)
  {
    if (user.username == username && user.password == password)
    {
      cout << "\nLogin successful." << "\nLogged in as " << user.role << "\n";

      return &user;
    }
  }
  cout << "\nInvalid username or password.\n";

  return nullptr;
}

void registerUser()
{
  vector<User> users = getUsers();

  string username;

  cout << "\nEnter new username: ";
  getline(cin, username);

  string password = inputPassword();

  for (const auto &user : users)
  {
    if (user.username == username)
    {
      cout << "\nUsername already exists. Please choose a different username.\n";
      return;
    }
  }

  users.push_back({username, "user", password});

  saveUsers(users);

  cout << "\nUser registered successfully.\n";
}