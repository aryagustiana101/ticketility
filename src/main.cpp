#include <vector>
#include <iostream>
#include "headers/menu.h"
#include "headers/banner.h"

using namespace std;

int main()
{
  banner();

  cout << "\nWelcome to Ticketility - Mock Ticketing App\n";

  authMenu();

  return 0;
}