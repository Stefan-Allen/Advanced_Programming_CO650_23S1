// RegularOrder.h

#ifndef REGULARORDER_H
#define REGULARORDER_H

#include "Order.h"

class RegularOrder : public Order {
public:
    // Constructor
    RegularOrder(const Menu *menu, const Customer *customer, int quantity, double discount);

    // Override the DisplayOrderString method
    std::string DisplayOrderString() const override;
};

#endif // REGULARORDER_H
