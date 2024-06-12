#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "headers/data.h"
#include "headers/user.h"
#include "headers/auth.h"
#include "headers/order.h"
#include "headers/utils.h"
#include "headers/ticket.h"
#include "headers/text-table.h"

using namespace std;

void adminMenu(User *user, Ticket *ticketTree)
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
      clearScreen();

      vector<TicketDetail> ticketDetails;
      inOrderTraversal(ticketTree, ticketDetails);

      cout << "\nAvailable Tickets: \n\n";

      displayTicketDetails(ticketDetails);

      break;
    }
    case 2:
    {
      clearScreen();

      vector<Order> orders;
      auto orderQueue = getOrderQueue();

      cout << "\nPending Orders: \n";

      if (orderQueue.empty())
      {
        cout << "Order queue is empty.\n";
        break;
      }

      while (!orderQueue.empty())
      {
        Order order = orderQueue.front();

        orders.push_back(order);

        orderQueue.pop();
      }

      cout << "\n";
      displayOrders(orders);

      break;
    }
    case 3:
    {
      clearScreen();

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
    {
      clearScreen();

      auto orders = getPendingOrders();
      displayOrders(orders);

      processPendingOrder();
      break;
    }
    case 5:
    {
      clearScreen();
      cout << "\nLogout successful.\n";
      break;
    }
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 5.\n";
    }
  } while (choice != 5);
}

void userMenu(User *user, Ticket *ticketTree)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nUser Menu:\n";
    cout << "1. Display Available Tickets\n";
    cout << "2. Display My Orders\n";
    cout << "3. Display My Balance\n";
    cout << "4. Create Order\n";
    cout << "5. Recharge Balance\n";
    cout << "6. Logout\n";
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
      clearScreen();

      TextTable t('-', '|', '+');
      vector<TicketDetail> ticketDetails = toTicketDetailCollection(ticketTree);

      cout << "\nAvailable Tickets: \n\n";

      displayTicketDetails(ticketDetails);

      break;
    }
    case 2:
    {
      clearScreen();

      vector<Order> userOrders;
      vector<Order> orders = getOrders();

      copy_if(orders.begin(), orders.end(), back_inserter(userOrders), [&](const Order &order)
              { return order.user == user->username; });

      cout << "\nYour Orders: \n";

      if (userOrders.size() == 0)
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
    {
      clearScreen();
      cout << "\n"
           << user->username << " balance: " << to_string(user->balance) << "\n";
      break;
    }
    case 4:
    {
      clearScreen();
      createOrder(user, ticketTree);
      break;
    }
    case 5:
    {
      clearScreen();
      rechargeBalance(user);
      break;
    }
    case 6:
    {
      clearScreen();
      cout << "\nLogout successful.\n";
      break;
    }
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 6.\n";
    }
  } while (choice != 6);
}

void authMenu(Ticket *ticketTree)
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
      clearScreen();

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
    {
      clearScreen();
      registerUser();
      break;
    }
    case 3:
    {
      clearScreen();
      cout << "\nExiting Ticketility. Goodbye!\n\n";
      break;
    }
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 3.\n";
    }
  } while (choice != 3);
}