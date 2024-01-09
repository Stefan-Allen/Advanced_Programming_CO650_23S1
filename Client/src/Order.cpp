#include "Order.h"
#include "Menu.h"
#include "Specials.h"
#include "Customer.h"
#include <iostream>

// Static variable to store orders
std::vector<Order> Order::orders;

// Constructors,initializing the state of Order objects.
Order::Order(const Menu *menu, const Customer *customer, int quantity, double discount)
    : menu(menu), customer(customer), quantity(quantity), discount(discount), isMenuOrder(true) {
}

// Constructor for Specials Order
Order::Order(const Specials *specials, const Customer *customer, int quantity, double discount)
    : specials(specials), customer(customer), quantity(quantity), discount(discount), isMenuOrder(false) {
}

// Polymorphism through class hierarchy.
double Order::CalculateTotal() const {
    if (isMenuOrder) {
        return (menu->GetPrice() * quantity) * (1.0 - discount);
    }
}

// Get customer associated with order
const Customer *Order::GetCustomer() const {
    return customer;
}

// Polymorphic Behaviour, display orders for a specific customer.
void Order::DisplayOrders(const Customer &customer) const {
    std::cout << "Orders for Customer: " << customer.GetName() << "\n";

    for (const auto &order: orders) {
        if (order.GetCustomer() == &customer) {
            order.DisplayOrderString(); // Display order details
        }
    }
}

// DisplayOrder method
std::string Order::DisplayOrderString() const {
    std::string orderString;

    if (isMenuOrder) {
        orderString += "Menu Item: " + menu->GetTitle() + "\n";
    } else {
        orderString += "Specials: " + specials->GetName() + "\n";
    }
    orderString += "Customer: " + customer->GetName() + "\n";
    orderString += "Quantity: " + std::to_string(quantity) + "\n";
    orderString += "Discount: " + std::to_string(discount * 100) + "%\n";
    orderString += "Total: $" + std::to_string(CalculateTotal()) + "\n";
    orderString += "------------------------\n";

    return orderString;
}
