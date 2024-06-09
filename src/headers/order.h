#ifndef ORDER_H
#define ORDER_H

#include <queue>
#include <vector>
#include "data.h"

vector<Order> getOrders();
void saveOrders(const vector<Order> &orders);
vector<Order> getPendingOrders();
queue<Order> getOrderQueue();
bool addOrderQueue(Order order);
void createOrder(User *user, const Ticket *ticketTree);
void displayOrders(vector<Order> orders);

#endif