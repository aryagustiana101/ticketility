#include <vector>
#include <string>
#include <iostream>
#include "headers/user.h"
#include "headers/data.h"

using namespace std;

User *login()
{
  vector<User> users = getUsers();

  string username, password;

  cout << "\nEnter username: ";
  getline(cin, username);
  cout << "Enter password: ";
  getline(cin, password);

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

  string username, password;

  cout << "\nEnter new username: ";
  getline(cin, username);
  cout << "Enter new password: ";
  getline(cin, password);

  for (const auto &user : users)
  {
    if (user.username == username)
    {
      cout << "\nUsername already exists. Please choose a different username.\n";
      return;
    }
  }

  User user;
  user.username = username;
  user.password = password;
  user.role = "user";
  users.push_back(user);

  saveUsers(users);

  cout << "\nUser registered successfully.\n";
}