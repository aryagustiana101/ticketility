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

string randomCode(vector<string> &usedCodes)
{
  string code;
  vector<string> codes = {"TX", "AU", "LAX", "BTC", "REZ"};

  do
  {
    code = codes[rand() % codes.size()];
  } while (find(usedCodes.begin(), usedCodes.end(), code) != usedCodes.end());

  usedCodes.push_back(code);

  return code;
}

void randomizeTickets(Ticket *root, int depth, int maxDepth)
{
  if (depth >= maxDepth)
  {
    return;
  }

  root->left = makeTicket({rand() % 501 + 100, generateCode(3), randomName()});
  randomizeTickets(root->left, depth + 1, maxDepth);

  root->right = makeTicket({rand() % 501 + 100, generateCode(3), randomName()});
  randomizeTickets(root->right, depth + 1, maxDepth);
}

Ticket *generateTicket()
{
  Ticket *root = makeTicket({0, "", ""});

  randomizeTickets(root, 0, 2);

  return root;
}

void inOrderTraversal(const Ticket *node)
{
  if (node == nullptr)
    return;

  inOrderTraversal(node->left);

  if (node->detail.code != "")
  {
    cout << "Code: " << node->detail.code << endl;
    cout << "Name: " << node->detail.name << endl;
    cout << "Price: " << node->detail.price << endl;
    cout << endl;
  }

  inOrderTraversal(node->right);
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
