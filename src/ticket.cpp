#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "headers/data.h"
#include "headers/utils.h"
#include "headers/text-table.h"

using namespace std;

Ticket *makeTicket(const TicketDetail &detail)
{
  Ticket *ticket = new Ticket;
  ticket->parent = nullptr;
  ticket->left = nullptr;
  ticket->right = nullptr;
  ticket->detail = detail;
  return ticket;
}

void randomizeTickets(Ticket *root, int depth, int maxDepth)
{
  if (depth >= maxDepth)
  {
    return;
  }

  root->left = makeTicket({
      generateCode(3),
      randomItem({"Adventure Pass", "DreamScape Ticket", "ABC Voucher", "NFL Ticket", "Excursion Token"}),
      rand() % 501 + 100,
  });

  randomizeTickets(root->left, depth + 1, maxDepth);

  root->right = makeTicket({
      generateCode(3),
      randomItem({"Adventure Pass", "DreamScape Ticket", "ABC Voucher", "NFL Ticket", "Excursion Token"}),
      rand() % 501 + 100,
  });

  randomizeTickets(root->right, depth + 1, maxDepth);
}

Ticket *generateTicket()
{
  Ticket *root = makeTicket({
      "",
      "",
      0,
  });

  randomizeTickets(root, 0, 2);

  return root;
}

void inOrderTraversal(const Ticket *node, vector<TicketDetail> &ticketDetails)
{
  if (node == nullptr)
  {
    return;
  }

  inOrderTraversal(node->left, ticketDetails);

  if (node->detail.code != "")
  {
    ticketDetails.push_back(node->detail);
  }

  inOrderTraversal(node->right, ticketDetails);
}

void preOrderTraversal(const Ticket *node, vector<TicketDetail> &ticketDetails)
{
  if (node == nullptr)
  {
    return;
  }

  if (node->detail.code != "")
  {
    ticketDetails.push_back(node->detail);
  }

  preOrderTraversal(node->left, ticketDetails);
  preOrderTraversal(node->right, ticketDetails);
}

TicketDetail *findTicketDetailByCode(const Ticket *node, const string &code)
{
  if (node == nullptr)
  {
    return nullptr;
  }

  if (node->detail.code == code)
  {
    return new TicketDetail(node->detail);
  }

  TicketDetail *leftResult = findTicketDetailByCode(node->left, code);
  if (leftResult != nullptr)
  {
    return leftResult;
  }

  TicketDetail *rightResult = findTicketDetailByCode(node->right, code);
  if (rightResult != nullptr)
  {
    return rightResult;
  }

  return nullptr;
}

void displayTicketDetails(vector<TicketDetail> ticketDetails)
{
  TextTable t('-', '|', '+');

  t.add("Code");
  t.add("Name");
  t.add("Price");
  t.endOfRow();

  for (const auto &ticketDetail : ticketDetails)
  {
    t.add(ticketDetail.code);
    t.add(ticketDetail.name);
    t.add(to_string(ticketDetail.price));
    t.endOfRow();
  }

  t.setAlignment(2, TextTable::Alignment::RIGHT);
  cout << t;
}