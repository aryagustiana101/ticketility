#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

using namespace std;

struct User
{
  string username;
  string password;
  string role;
};

struct TicketDetail
{
  int price;
  string code;
  string name;
};

struct Ticket
{
  Ticket *parent;
  Ticket *left;
  Ticket *right;
  TicketDetail detail;
};

#endif