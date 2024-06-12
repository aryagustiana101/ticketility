#ifndef MENU_H
#define MENU_H

#include "data.h"

void adminMenu(User *user, Ticket *ticketTree);
void userMenu(User *user, Ticket *ticketTree);
void authMenu(Ticket *ticketTree);

#endif
