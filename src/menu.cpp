#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "headers/data.h"
#include "headers/auth.h"
#include "headers/ticket.h"

using namespace std;

void userMenu(const Ticket *ticket)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nUser Menu:\n";
    cout << "1. Display Available Ticket\n";
    cout << "2. Check Order\n";
    cout << "3. Create New Order\n";
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
      cout << "\n";
      inOrderTraversal(ticket);
      break;
    }
    case 2:
      break;
    case 3:
      break;
    case 4:
      cout << "\nLogout successful.\n";
      break;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 4.\n";
    }
  } while (choice != 4);
}

void authMenu(const Ticket *ticket)
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

      if (user != nullptr)
      {
        if (user->role == "user")
        {
          userMenu(ticket);
        }
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