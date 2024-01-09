#ifndef MENUITEMS_H
#define MENUITEMS_H

#pragma once
#include <memory>
#include <vector>
#include "Menu.h"
#include "Specials.h"
#include "Order.h"
#include "Customer.h"

// Polymorphic Behavior, Function overloading handles both Menu and Specials objects.
// Abstraction, a collection of menus, specials, customers, and orders.
class MenuItems {
public:
    // Constructors, Used for initializing the state of MenuItems.
    MenuItems();

    // Encapsulation, Private members are used to encapsulate the state of the MenuItems class.
    void AddMenu(const Menu &menu);

    void AddSpecials(const Specials &specials);

    void AddCustomer(const Customer &customer);

    // Polymorphic Behavior, Overloaded methods allow placing orders for both Menu and Specials.
    void PlaceOrder(const Menu &menu, const Customer &customer, int quantity);

    void PlaceOrder(const Specials &specials, const Customer &customer, int quantity);

    // Displaying state of the MenuItems object.
    void DisplayInventory() const;

    void DisplayCustomerOrders(const Customer &customer) const;

    // display orders for a specific customer.
    std::string DisplayOrders(const Customer &customer) const;

    // Static Members keep track of the total number of orders across MenuItems.
    static int GetTotalOrders();

    // Friendship, MenuItems class is a friend of the Order class, allowing access to private members.
    friend class Order;

private:
    // Collections to store menus, special items, customers, and orders.
    std::vector<std::unique_ptr<Menu> > menus;
    std::vector<std::unique_ptr<Specials> > specialItems;
    std::vector<Customer> customers;
    std::vector<Order> orders;

    // Static Members, Keeps track of the total number of orders.
    static int totalOrders;

    // Indicates between Menu and Specials orders.
    bool isMenuOrder;

    // Functional Pointers processing orders.
    using OrderProcessor = double (MenuItems::*)(const Order &) const;
    OrderProcessor processOrder;

    // Polymorphic Behaviour through class hierarchy.
    double CalculateTotal(const Order &order) const;
};

#endif // MENUITEMS_H
