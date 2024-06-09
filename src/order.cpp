#include <queue>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "headers/data.h"
#include "headers/utils.h"
#include "headers/ticket.h"
#include "headers/storage.h"
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

const size_t MAX_QUEUE_SIZE = 5;
const string STORAGE_FILENAME = "orders.json";

vector<Order> getOrders()
{
  vector<Order> orders;

  json data = readStorage(STORAGE_FILENAME);

  for (const auto &item : data)
  {
    Order order = {item["code"], item["status"], item["amount"], item["date"], item["user"], {item["ticket"]["code"], item["ticket"]["name"], item["ticket"]["price"]}};

    orders.push_back(order);
  }

  return orders;
}

void saveOrders(const vector<Order> &orders)
{
  json data;

  for (const auto &order : orders)
  {
    data.push_back({
        {"code", order.code},
        {"status", order.status},
        {"amount", order.amount},
        {"date", order.date},
        {"user", order.user},
        {"ticket", {{"code", order.ticket.code}, {"name", order.ticket.name}, {"price", order.ticket.price}}},
    });
  }

  writeStorage(STORAGE_FILENAME, data);
}

vector<Order> getPendingOrders()
{
  vector<Order> result;
  vector<Order> orders = getOrders();

  copy_if(orders.begin(), orders.end(), back_inserter(result), [&](const Order &order)
          { return order.status == "pending"; });

  return result;
}

queue<Order> getOrderQueue()
{
  queue<Order> line;
  vector<Order> orders = getPendingOrders();

  for (const auto &order : orders)
  {
    line.push(order);
  }

  return line;
}

bool addOrderQueue(Order order)
{
  queue<Order> line = getOrderQueue();

  if (line.size() < MAX_QUEUE_SIZE)
  {
    vector<Order> orders = getOrders();

    orders.push_back(order);

    saveOrders(orders);
  }

  return line.size() < MAX_QUEUE_SIZE;
}

void createOrder(User *user, const Ticket *ticketTree)
{
  string ticketCode;

  cout << "\nEnter the code of the ticket: ";
  getline(cin, ticketCode);

  TicketDetail *ticket = findTicketDetailByCode(ticketTree, ticketCode);

  if (ticket == nullptr)
  {
    cout << "\nTicket with code " << ticketCode << " not found.\n";
    return;
  }

  int amount;
  string _amount;

  cout << "Enter order amount: ";
  getline(cin, _amount);

  stringstream ss(_amount);

  if (!(ss >> amount))
  {
    cout << "\nInvalid input. Please enter a number.\n";
    return;
  }

  bool result = addOrderQueue(
      {generateCode(3),
       "pending",
       amount,
       getCurrentDateTime(),
       user->username,
       {ticket->code, ticket->name, ticket->price}});

  cout << (result ? "Order successfully added to the queue." : "Order queue is full, please try again in a few moment.") << "\n";
}

void displayOrders(vector<Order> orders)
{
  for (const auto &order : orders)
  {
    cout << "Order Code: " << order.code << "\n";
    cout << "Order Status: " << order.status << "\n";
    cout << "Order Amount: " << order.amount << "\n";
    cout << "Order Date: " << order.date << "\n";
    cout << "Order Total: " << order.ticket.price * order.amount << "\n";
    cout << "User: " << order.user << "\n";
    cout << "Ticket Code: " << order.ticket.code << "\n";
    cout << "Ticket Name: " << order.ticket.name << "\n";
    cout << "Ticket Price: " << order.ticket.price << "\n";
    cout << "------------------\n\n";
  }
}