#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include "../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

json readStorage(const string &filename);
void writeStorage(const string &filename, const json &data);

#endif