#include "Customer.h"
#include "Order.h"

// Constructor that initializes name.
Customer::Customer(const std::string &name)
    : name(name) {
}

// Getter to retrieve the name of customer.
std::string Customer::GetName() const {
    return name;
}
