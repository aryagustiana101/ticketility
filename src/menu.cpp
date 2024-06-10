#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "headers/data.h"
#include "headers/auth.h"
#include "headers/order.h"
#include "headers/ticket.h"

using namespace std;

void adminMenu(User *user, const Ticket *ticketTree)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nAdmin Menu:\n";
    cout << "1. Display Available Tickets\n";
    cout << "2. Display Order Queue\n";
    cout << "3. Display All Orders\n";
    cout << "4. Process Pending Order\n";
    cout << "5. Logout\n";
    cout << "\nEnter your choice: ";
    getline(cin, _choice);

    stringstream ss(_choice);

    if (!(ss >> choice))
    {
      cout << "\nInvalid input. Please enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
    {
      cout << "\nAvailable Tickets: \n\n";
      inOrderTraversal(ticketTree);
      break;
    }
    case 2:
    {
      auto orderQueue = getOrderQueue();

      if (orderQueue.empty())
      {
        cout << "\nOrder queue is empty.\n";
      }

      cout << "\nPending Orders: \n";

      while (!orderQueue.empty())
      {
        Order order = orderQueue.front();
        displayOrder(order);
        orderQueue.pop();
      }

      break;
    }
    case 3:
    {
      vector<Order> orders = getOrders();

      cout << "\nAll Orders: \n";

      if (orders.size() == 0)
      {
        cout << "Order not found.\n";
      }
      else
      {
        cout << "\n";
        displayOrders(orders);
      }

      break;
    }
    case 4:
      processPendingOrder();
      break;
    case 5:
      cout << "\nLogout successful.\n";
      break;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 5.\n";
    }
  } while (choice != 5);
}

void userMenu(User *user, const Ticket *ticketTree)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nUser Menu:\n";
    cout << "1. Display Available Tickets\n";
    cout << "2. Display My Orders\n";
    cout << "3. Create Order\n";
    cout << "4. Logout\n";
    cout << "\nEnter your choice: ";
    getline(cin, _choice);

    stringstream ss(_choice);

    if (!(ss >> choice))
    {
      cout << "\nInvalid input. Please enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
    {
      cout << "\nAvailable Tickets: \n\n";
      preOrderTraversal(ticketTree);
      break;
    }
    case 2:
    {
      vector<Order> userOrders;
      vector<Order> orders = getOrders();

      copy_if(orders.begin(), orders.end(), back_inserter(userOrders), [&](const Order &order)
              { return order.user == user->username; });

      cout << "\nYour Orders: \n";

      if (orders.size() == 0)
      {
        cout << "Order not found.\n";
      }
      else
      {
        cout << "\n";
        displayOrders(userOrders);
      }

      break;
    }
    case 3:
      createOrder(user, ticketTree);
      break;
    case 4:
      cout << "\nLogout successful.\n";
      break;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 4.\n";
    }
  } while (choice != 4);
}

void authMenu(const Ticket *ticketTree)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nAuthentication Menu:\n";
    cout << "1. Login\n";
    cout << "2. Register New User\n";
    cout << "3. Exit\n";
    cout << "\nEnter your choice: ";
    getline(cin, _choice);

    stringstream ss(_choice);

    if (!(ss >> choice))
    {
      cout << "\nInvalid input. Please enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
    {
      User *user = login();

      if (user != nullptr && user->role == "user")
      {
        userMenu(user, ticketTree);
      }

      if (user != nullptr && user->role == "admin")
      {
        adminMenu(user, ticketTree);
      }

      break;
    }
    case 2:
      registerUser();
      break;
    case 3:
      cout << "\nExiting Ticketility. Goodbye!\n\n";
      break;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 3.\n";
    }
  } while (choice != 3);
}