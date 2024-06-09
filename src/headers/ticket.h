#ifndef TICKET_H
#define TICKET_H

#include "data.h"

Ticket *makeTicket(const TicketDetail &detail);
void randomizeTickets(Ticket *root, int depth, int maxDepth);
Ticket *generateTicket();
void displayTicketDetail(TicketDetail detail);
void inOrderTraversal(const Ticket *node);
void preOrderTraversal(const Ticket *node);
TicketDetail *findTicketDetailByCode(const Ticket *node, const string &code);

#endif