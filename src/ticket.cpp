#include <string>
#include <iostream>
#include <algorithm>
#include "headers/data.h"
#include "headers/utils.h"

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

void displayTicketDetail(TicketDetail detail)
{
  cout << "Code: " << detail.code << "\n";
  cout << "Name: " << detail.name << "\n";
  cout << "Price: " << detail.price << "\n";
  cout << "------------------\n\n";
}

void inOrderTraversal(const Ticket *node)
{
  if (node == nullptr)
  {
    return;
  }

  inOrderTraversal(node->left);

  if (node->detail.code != "")
  {
    displayTicketDetail(node->detail);
  }

  inOrderTraversal(node->right);
}

void preOrderTraversal(const Ticket *node)
{
  if (node == nullptr)
  {
    return;
  }

  if (node->detail.code != "")
  {
    displayTicketDetail(node->detail);
  }

  preOrderTraversal(node->left);
  preOrderTraversal(node->right);
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