#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <vector>
#include "data.h"

Ticket *makeTicket(const TicketDetail &detail);
void randomizeTickets(Ticket *root, int depth, int maxDepth);
Ticket *generateTicket();
void inOrderTraversal(const Ticket *node, vector<TicketDetail> &ticketDetails);
void preOrderTraversal(const Ticket *node, vector<TicketDetail> &ticketDetails);
TicketDetail *findTicketDetailByCode(const Ticket *node, const string &code);
vector<TicketDetail> toTicketDetailCollection(const Ticket *ticketTree);
void displayTicketDetails(vector<TicketDetail> ticketDetails);
bool updateTicketStock(Ticket *node, const string &code, int newStock);

#endif