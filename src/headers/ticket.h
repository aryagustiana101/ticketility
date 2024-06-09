#ifndef TICKET_H
#define TICKET_H

#include "data.h"

Ticket *generateTicket();
void inOrderTraversal(const Ticket *node);
bool findTicketByCode(const Ticket *node, const string &code);

#endif