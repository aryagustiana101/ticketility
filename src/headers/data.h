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
};

struct TicketDetail
{
  string code;
  string name;
  int price;
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
  string user;
  TicketDetail ticketDetail;
};

#endif