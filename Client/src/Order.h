#ifndef ORDER_H
#define ORDER_H

#include "Menu.h"
#include "Specials.h"
#include "Customer.h"
#include <vector>  // Include the vector header

class MenuItems; // Forward declaration

class Order {
public:
    // Constructors Used for initializing the state of Order.
    Order(const Menu *menu, const Customer *customer, int quantity, double discount);

    Order(const Specials *specials, const Customer *customer, int quantity, double discount);

    // rder class is using polymorphism through inheritance.
    class OrderException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "OrderException: An exception occurred while processing an order.";
        }
    };

    // Polymorphism through class hierarchy.
    double CalculateTotal() const;

    void DisplayOrders(const Customer &customer) const;

    const Customer *GetCustomer() const;

    // DisplayOrder method
    std::string DisplayOrderString() const;

private:
    // Encapsulation, Private data members
    const Menu *menu; // Pointer to a Menu object
    const Specials *specials; // Pointer to a Specials object
    const Customer *customer; // Pointer to a Customer object
    int quantity;
    double discount;
    bool isMenuOrder; // Indicates if the order is for a menu item or a specials item

    // Static variable to store orders
    static std::vector<Order> orders;

    // DisplayOrder method
    void DisplayOrder() const;

    // The MenuItems class is a friend, allowing access to private members.
    friend class MenuItems;
};

#endif // ORDER_H
