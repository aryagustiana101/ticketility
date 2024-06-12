#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

using namespace std;

struct User
{
  string username;
  string role;
  string password;
  int balance;
};

struct TicketDetail
{
  string code;
  string name;
  int price;
  int stock;
};

struct Ticket
{
  Ticket *parent;
  Ticket *left;
  Ticket *right;
  TicketDetail detail;
};

struct Order
{
  string code;
  string status;
  int amount;
  string date;
  string user;
  TicketDetail ticket;
};

#endif