#ifndef MENUITEMS_H
#define MENUITEMS_H

#pragma once
#include <memory>
#include <vector>
#include "Menu.h"
#include "Specials.h"
#include "Order.h"
#include "Customer.h"

// Abstraction, collection of menus, specials, customers, and orders.
// Encapsulate the internal state of the MenuItems class.
class MenuItems {
public:
    // Constructors, initializing the state of MenuItems.
    MenuItems();

    // Method to add a menu item.
    void AddMenu(const Menu &menu);

    // Method to add a specials item.
    void AddSpecials(const Specials &specials);

    // Method to add a customer.
    void AddCustomer(const Customer &customer);

    // Polymorphic Behavior, Oallow placing orders for both Menu and Specials.
    // Find Menu by Name
    const Menu *FindMenuByName(const std::string &itemName) const;

    // Find Specials by Name
    const Specials *FindSpecialsByName(const std::string &itemName) const;

    // Place Order for Menu Item with a Customer
    void PlaceOrder(const Menu &menu, const Customer &customer, int quantity);

    // Place Order for Specials Item with a Customer
    void PlaceOrder(const Specials &specials, const Customer &customer, int quantity);

    // Display methods for state of the MenuItems object.
    void DisplayInventory() const;

    // Method to display customer orders using functional pointers.
    void DisplayCustomerOrders(const Customer &customer) const;

    // Method to display orders for a specific customer.
    void DisplayOrders(const Customer &customer) const;

    // Static member to keep track of the total number of orders.
    static int GetTotalOrders();

    // Friend of the Order class, allowing access to private members.
    friend class Order;

private:
    // Collections to store menus, special items, customers, and orders.
    std::vector<std::unique_ptr<Menu> > menus;
    std::vector<std::unique_ptr<Specials> > specialItems;
    std::vector<Customer> customers;
    std::vector<Order> orders;

    // Static Members to keep track of the total number of orders across MenuItems.
    static int totalOrders;

    // To differentiate between menu and special orders.
    bool isMenuOrder;

    // Functional pointers for processing orders.
    using OrderProcessor = double (MenuItems::*)(const Order &) const;
    OrderProcessor processOrder;

    // Polymorphism through class hierarchy.
    double CalculateTotal(const Order &order) const;
};

#endif // MENUITEMS_H
