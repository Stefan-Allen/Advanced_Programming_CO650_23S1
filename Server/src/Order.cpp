#include "Order.h"
#include "Menu.h"
#include "Specials.h"
#include "Customer.h"
#include <iostream>

// Static member variable
std::vector<Order> Order::orders;

// Constructors, initializingstate of Order objects.
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
    } else {
        return (specials->GetPrice() * quantity) * (1.0 - discount);
    }
}

// Method to get the customer with the order
const Customer *Order::GetCustomer() const {
    return customer;
}

// Display orders for a specific customer.
void Order::DisplayOrders(const Customer &customer) const {
    std::cout << "Orders for Customer: " << customer.GetName() << "\n";

    for (const auto &order: orders) {
        if (order.GetCustomer() == &customer) {
            order.DisplayOrder(); // Display order details
        }
    }
}

// DisplayOrder method
void Order::DisplayOrder() const {
    if (isMenuOrder) {
        std::cout << "Menu Item: " << menu->GetTitle() << std::endl;
    } else {
        std::cout << "Specials: " << specials->GetName() << std::endl;
    }
    std::cout << "Customer: " << customer->GetName() << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Discount: " << (discount * 100) << "%" << std::endl;
    std::cout << "Total: $" << CalculateTotal() << std::endl;

    std::cout << "------------------------\n";
}
