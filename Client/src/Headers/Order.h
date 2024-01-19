#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>

#include "Exception.h"

// Forward declarations
class Menu;
class Specials;
class RegularOrder;
class MenuItems;

class Customer;

class Order {
public:
    // Constructors
    Order(const Menu *menu, const Customer *customer, int quantity, double discount);

    Order(const Specials *specials, const Customer *customer, int quantity, double discount);

    Order(const RegularOrder *regularOrder);

    // Static Members
    static std::vector<Order>& GetOrders();

    // Exception Handling using Exception Classes (Inheriting from Exception)
    class OrderException : public Exception {
    public:
        using Exception::Exception; // Inherit constructors from Exception
    };

    // Polymorphic behavior
    virtual double CalculateTotal() const;

    void DisplayOrders(const Customer &customer) const;

    const Customer *GetCustomer() const;

    virtual std::string DisplayOrderString() const;

protected:
    const Menu *menu;
    const Specials *specials;
    const Customer *customer;
    int quantity;
    double discount;
    bool isMenuOrder;

private:
    static std::vector<Order> orders;

    friend class MenuItems;
};

#endif // ORDER_H
