#include <vector>
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
    User user = {item["username"], item["role"], item["password"]};

    users.push_back(user);

    if (user.username == "root")
    {
      rootExists = true;
    }
  }

  if (!rootExists)
  {
    users.push_back({
        "root",
        "admin",
        "123",
    });
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

  writeStorage(STORAGE_FILENAME, data);
}