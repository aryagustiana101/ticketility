#include <vector>
#include <iostream>
#include "headers/menu.h"
#include "headers/data.h"
#include "headers/utils.h"
#include "headers/ticket.h"
#include "headers/banner.h"

using namespace std;

int main()
{
  srand(time(0));

  Ticket *ticket = generateTicket();

  banner();

  cout << "\nWelcome to Ticketility - Mock Ticketing App\n";

  authMenu(ticket);

  return 0;
}