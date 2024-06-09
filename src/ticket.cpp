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

string randomName()
{
  vector<string> names = {"Adventure Pass", "DreamScape Ticket", "ABC Voucher", "NFL Ticket", "Excursion Token"};

  return names[rand() % names.size()];
}

void randomizeTickets(Ticket *root, int depth, int maxDepth)
{
  if (depth >= maxDepth)
  {
    return;
  }

  root->left = makeTicket({
      generateCode(3),
      randomName(),
      rand() % 501 + 100,
  });

  randomizeTickets(root->left, depth + 1, maxDepth);

  root->right = makeTicket({
      generateCode(3),
      randomName(),
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
  cout << "\n";
}

void inOrderTraversal(const Ticket *node)
{
  if (node == nullptr)
  {
    return;
  }

  inOrderTraversal(node->left);

  displayTicketDetail(node->detail);

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

  displayTicketDetail(node->detail);

  if (node->detail.code != "")
  {
    displayTicketDetail(node->detail);
  }

  preOrderTraversal(node->left);
  preOrderTraversal(node->right);
}

bool findTicketByCode(const Ticket *node, const string &code)
{
  if (node == nullptr)
  {
    return false;
  }

  if (node->detail.code == code)
  {
    return true;
  }

  if (findTicketByCode(node->left, code) || findTicketByCode(node->right, code))
  {
    return true;
  }

  return false;
}
