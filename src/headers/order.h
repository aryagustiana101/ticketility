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
void displayOrder(Order order);
void displayOrders(vector<Order> orders);
bool findOrderByCode(string code);
void processPendingOrder();

#endif