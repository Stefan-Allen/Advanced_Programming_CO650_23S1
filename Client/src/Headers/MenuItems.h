#ifndef MENUITEMS_H
#define MENUITEMS_H

#pragma once
#include <memory>
#include <vector>
#include "Menu.h"
#include "Specials.h"
#include "Order.h"
#include "Customer.h"

// Abstraction
// Polymorphic Behavior
class MenuItems {
public:
    // Constructors
    MenuItems();

    std::string DisplayOrders(const Customer &customer) const;

    // Encapsulation
    void AddMenu(const Menu &menu);

    void AddSpecials(const Specials &specials);

    void AddCustomer(const Customer &customer);

    // Polymorphic Behavior
    void PlaceOrder(const Menu &menu, const Customer &customer, int quantity);

    void PlaceOrder(const Specials &specials, const Customer &customer, int quantity);

    void DisplayInventory() const;

    void DisplayCustomerOrders(const Customer &customer) const;

    // Static Members
    static int GetTotalOrders();

    // Friendship
    friend class Order;

private:
    // Collections to store menus, special items, customers, and orders.
    std::vector<std::unique_ptr<Menu> > menus;
    std::vector<std::unique_ptr<Specials> > specialItems;
    std::vector<Customer> customers;
    std::vector<Order> orders;

    // Static Members, Keeps track of the total number of orders.
    static int totalOrders;

    // Functional Pointers processing orders.
    using OrderProcessor = double (MenuItems::*)(const Order &) const;
    OrderProcessor processOrder;

    // Polymorphic Behaviour through class hierarchy.
    double CalculateTotal(const Order &order) const;
};

#endif // MENUITEMS_H
