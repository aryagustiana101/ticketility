#ifndef USER_H
#define USER_H

#include <vector>
#include "data.h"

vector<User> getUsers();
void saveUsers(const vector<User> &users);
void rechargeBalance(User *_user);

#endif