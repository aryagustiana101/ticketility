#ifndef MENU_H
#define MENU_H

#include "data.h"

void adminMenu(User *user, const Ticket *ticketTree);
void userMenu(User *user, const Ticket *ticketTree);
void authMenu(const Ticket *ticketTree);

#endif
