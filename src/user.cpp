#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "headers/data.h"
#include "headers/storage.h"
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

const string STORAGE_FILENAME = "users.json";

vector<User> getUsers()
{
  vector<User> users;

  json data = readStorage(STORAGE_FILENAME);

  bool rootExists = false;

  for (const auto &item : data)
  {
    User user = {
        item["username"],
        item["role"],
        item["password"],
        item["balance"],
    };

    users.push_back(user);

    if (user.username == "root")
    {
      rootExists = true;
    }
  }

  if (!rootExists)
  {
    users.push_back({"root",
                     "admin",
                     "123",
                     0});
  }

  return users;
}

void saveUsers(const vector<User> &users)
{
  json data;
  bool rootExists = false;

  for (const auto &user : users)
  {
    data.push_back({{"username", user.username},
                    {"password", user.password},
                    {"role", user.role},
                    {"balance", user.balance}});

    if (user.username == "root")
    {
      rootExists = true;
    }
  }

  if (!rootExists)
  {
    data.push_back({{"username", "root"},
                    {"password", "123"},
                    {"role", "admin"},
                    {"balance", 0}});
  }

  writeStorage(STORAGE_FILENAME, data);
}

void rechargeBalance(User *_user)
{
  int amount;
  string _amount;

  cout << "Enter amount to recharge: ";
  getline(cin, _amount);

  stringstream ss(_amount);

  if (!(ss >> amount))
  {
    cout << "\nInvalid input. Please enter a number.\n";
    return;
  }

  string confirmation;

  cout << "\n\nAre you sure you want to recharge " << amount << " to your balance? (y/n): ";
  getline(cin, confirmation);

  if (confirmation == "y" || confirmation == "Y")
  {
    auto users = getUsers();

    for (auto &user : users)
    {
      if (user.username == _user->username)
      {
        int total = user.balance + amount;
        user.balance = total;
        _user->balance = total;
      }
    }

    saveUsers(users);

    cout << "\nUser balance recharged successfully.\n";
  }
  else
  {
    cout << "\nOperation cancelled.\n";
  }
}