#include "../Headers/Order.h"

#include <iostream>

#include "../Headers/Menu.h"
#include "../Headers/Specials.h"
#include "../Headers/Customer.h"
#include "../Headers/RegularOrder.h"

std::vector<Order> Order::orders;

Order::Order(const Menu *menu, const Customer *customer, int quantity, double discount)
    : menu(menu), specials(nullptr), customer(customer), quantity(quantity), discount(discount), isMenuOrder(true) {
}

Order::Order(const Specials *specials, const Customer *customer, int quantity, double discount)
    : menu(nullptr), specials(specials), customer(customer), quantity(quantity), discount(discount),
      isMenuOrder(false) {
}

Order::Order(const RegularOrder *regularOrder)
    : menu(regularOrder->menu), specials(nullptr), customer(regularOrder->customer),
      quantity(regularOrder->quantity), discount(regularOrder->discount), isMenuOrder(true) {
}

// Static function to access the orders vector
std::vector<Order> &Order::GetOrders() {
    return orders;
}

// Polymorphism through class hierarchy.
double Order::CalculateTotal() const {
    if (isMenuOrder) {
        return (menu->GetPrice() * quantity) * (1.0 - discount);
    }
    return 0.0; // Return a default value
}

// Get customer associated with order
const Customer *Order::GetCustomer() const {
    return customer;
}

// Polymorphic Behaviour: Display orders for a specific customer.
void Order::DisplayOrders(const Customer &customer) const {
    std::cout << "Orders for Customer: " << customer.GetName() << "\n";

    for (const auto &order: orders) {
        double total = order.CalculateTotal(); // Polymorphic behavior
        std::cout << order.DisplayOrderString(); // Display order details
        std::cout << "Total: $" << std::to_string(total) << "\n";
        std::cout << "------------------------\n";
    }
}

// DisplayOrder method for server
std::string Order::DisplayOrderString() const {
    std::string orderString;
    orderString += "Customer: " + customer->GetName() + "\n";
    orderString += "Discount: " + std::to_string(discount * 100) + "%\n";
    orderString += "Total: $" + std::to_string(CalculateTotal()) + "\n";
    orderString += "------------------------\n";

    return orderString;
}
