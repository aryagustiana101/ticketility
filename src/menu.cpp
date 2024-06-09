#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "headers/data.h"
#include "headers/auth.h"

using namespace std;

void authMenu()
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
        cout << "OK";
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