#ifndef TICKET_H
#define TICKET_H

#include <vector>
#include "data.h"

Ticket *makeTicket(const TicketDetail &detail);
void randomizeTickets(Ticket *root, int depth, int maxDepth);
Ticket *generateTicket();
void inOrderTraversal(const Ticket *node, vector<TicketDetail> &ticketDetails);
void preOrderTraversal(const Ticket *node, vector<TicketDetail> &ticketDetails);
TicketDetail *findTicketDetailByCode(const Ticket *node, const string &code);
void displayTicketDetails(vector<TicketDetail> ticketDetails);

#endif