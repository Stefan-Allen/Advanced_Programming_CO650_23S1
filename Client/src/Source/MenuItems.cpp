#include "../Headers/MenuItems.h"
#include <iostream>

// Static member totalOrders.
int MenuItems::totalOrders = 0;

// Constructors, MenuItems class and clears data structures.
MenuItems::MenuItems() {
    menus.clear();
    specialItems.clear();
    customers.clear();
    orders.clear();
    totalOrders = 0;

    // Functional Pointers, Initialize order processing and function pointer.
    processOrder = &MenuItems::CalculateTotal;
}

// Polymorphic Behaviour: Process orders and calculate total.
double MenuItems::CalculateTotal(const Order &order) const {
    double total = order.CalculateTotal();
    return total;
}

// Polymorphic Behaviour displaying customer orders using functional pointers.
void MenuItems::DisplayCustomerOrders(const Customer &customer) const {
    std::cout << "Orders for Customer: " << customer.GetName() << "\n";

    // total amount
    double totalAmount = 0.0;

    for (const auto &order: orders) {
        if (order.GetCustomer() == &customer) {
            // Accumulate the total amount
            totalAmount += (this->*processOrder)(order);
        }
    }

    // Display total amount
    std::cout << "Total: $" << totalAmount << std::endl;

    std::cout << "------------------------\n";
}

// Method to display orders for a specific customer.
std::string MenuItems::DisplayOrders(const Customer &customer) const {
    std::string ordersString;
    ordersString += "Orders for Customer: " + customer.GetName() + "\n";

    for (const auto &order: orders) {
        if (order.GetCustomer() == &customer) {
            // Append order details to the string
            ordersString += order.DisplayOrderString();
        }
    }
    return ordersString;
}

// Method to add a menu item.
void MenuItems::AddMenu(const Menu &menu) {
    menus.push_back(std::make_unique<Menu>(menu));
}

// Method to add a specials item.
void MenuItems::AddSpecials(const Specials &specials) {
    specialItems.push_back(std::make_unique<Specials>(specials));
}

// Method to add a customer.
void MenuItems::AddCustomer(const Customer &customer) {
    customers.push_back(customer);
}

// Method to place an order for a menu item.
void MenuItems::PlaceOrder(const Menu &menu, const Customer &customer, int quantity) {
    try {
        Order order(&menu, &customer, quantity, 0.05);
        orders.push_back(order);
        totalOrders = orders.size(); // Update totalOrders dynamically based on the number of orders
    } catch (const Order::OrderException &ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}

// Method to place an order for a specials item.
void MenuItems::PlaceOrder(const Specials &specials, const Customer &customer, int quantity) {
    try {
        Order order(&specials, &customer, quantity, 0.05);
        orders.push_back(order);
        totalOrders = orders.size(); // Update totalOrders dynamically based on the number of orders
    } catch (const Order::OrderException &ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}



// Static member to keep track of the total number of orders.
int MenuItems::GetTotalOrders() {
    return totalOrders;
}
