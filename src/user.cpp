#include <vector>
#include "headers/data.h"
#include "headers/storage.h"
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

const string USERS_FILENAME = "users.json";

vector<User> getUsers()
{
  vector<User> users;

  json data = readStorage(USERS_FILENAME);

  bool rootExists = false;

  for (const auto &item : data)
  {
    User user;
    user.username = item["username"];
    user.password = item["password"];
    user.role = item["role"];
    users.push_back(user);

    if (user.username == "root")
    {
      rootExists = true;
    }
  }

  if (!rootExists)
  {
    User user;
    user.username = "root";
    user.password = "123";
    user.role = "admin";
    users.push_back(user);
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
                    {"role", user.role}});

    if (user.username == "root")
    {
      rootExists = true;
    }
  }

  if (!rootExists)
  {
    data.push_back({{"username", "root"},
                    {"password", "123"},
                    {"role", "admin"}});
  }

  writeStorage(USERS_FILENAME, data);
}