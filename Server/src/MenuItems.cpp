#include "MenuItems.h"
#include <iostream>

// Static member totalOrders.
int MenuItems::totalOrders = 0;

// Constructor, Initializes MenuItems class and clears data structures.
MenuItems::MenuItems() {
    menus.clear();
    specialItems.clear();
    customers.clear();
    orders.clear();
    totalOrders = 0;

    // Processing function pointer.
    processOrder = &MenuItems::CalculateTotal;
}

// Process orders and calculate total.
double MenuItems::CalculateTotal(const Order &order) const {
    double total = order.CalculateTotal();
    return total;
}

// Display customer orders using functional pointers.
void MenuItems::DisplayCustomerOrders(const Customer &customer) const {
    std::cout << "Orders for Customer: " << customer.GetName() << "\n";

    // Accumulator for the total amount
    double totalAmount = 0.0;

    for (const auto &order: orders) {
        if (order.GetCustomer() == &customer) {
            // Accumulate the total amount
            totalAmount += (this->*processOrder)(order);
        }
    }

    // Display the total amount
    std::cout << "Total: $" << totalAmount << std::endl;

    std::cout << "------------------------\n";
}

const Menu *MenuItems::FindMenuByName(const std::string &itemName) const {
    for (const auto &menu: menus) {
        if (menu->GetName() == itemName) {
            return menu.get();
        }
    }
    return nullptr;
}

const Specials *MenuItems::FindSpecialsByName(const std::string &itemName) const {
    for (const auto &specials: specialItems) {
        if (specials->GetName() == itemName) {
            return specials.get();
        }
    }
    return nullptr;
}

// Display orders for a specific customer.
void MenuItems::DisplayOrders(const Customer &customer) const {
    std::cout << "Orders for Customer: " << customer.GetName() << "\n";

    for (const auto &order: orders) {
        if (order.GetCustomer() == &customer) {
            // Display order details using DisplayOrder from the order class
            order.DisplayOrder();
        }
    }
}


// Add a menu item.
void MenuItems::AddMenu(const Menu &menu) {
    menus.push_back(std::make_unique<Menu>(menu));
}

// Add a specials item.
void MenuItems::AddSpecials(const Specials &specials) {
    specialItems.push_back(std::make_unique<Specials>(specials));
}

// Add a customer.
void MenuItems::AddCustomer(const Customer &customer) {
    customers.push_back(customer);
}

// Method to place an order for menu item.
void MenuItems::PlaceOrder(const Menu &menu, const Customer &customer, int quantity) {
    try {
        Order order(&menu, &customer, quantity, 0.05);
        orders.push_back(order);
        totalOrders = orders.size(); // Update totalOrders dynamically based on the number of orders
    } catch (const Order::OrderException &ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}

// Method to place an order for specials item.
void MenuItems::PlaceOrder(const Specials &specials, const Customer &customer, int quantity) {
    try {
        Order order(&specials, &customer, quantity, 0.05);
        orders.push_back(order);
        totalOrders = orders.size(); // Update totalOrders dynamically based on the number of orders
    } catch (const Order::OrderException &ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}

// Display the inventory.
void MenuItems::DisplayInventory() const {
    std::cout << "------------------------\n";
    std::cout << "Main Menu." << std::endl;
    std::cout << "------------------------" << std::endl;

    for (const auto &menu: menus) {
        std::cout << menu->GetInfo() << std::endl;
    }

    std::cout << "------------------------\n";
    std::cout << "Today's Specials." << std::endl;
    std::cout << "------------------------" << std::endl;

    for (const auto &specials: specialItems) {
        std::cout << specials->GetInfo() << std::endl;
    }

    std::cout << "------------------------\n";
}

// Get the total number of orders.
int MenuItems::GetTotalOrders() {
    return totalOrders;
}
