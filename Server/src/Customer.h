#ifndef CUSTOMER_H
#define CUSTOMER_H

#pragma once
#include <string>

class Customer {
public:
    // Constructor that initializes its name member.
    Customer(const std::string &name);

    // Abstractio, retrieve the name of the customer.
    std::string GetName() const;

private:
    // Encapsulation, store the name of the customer.
    std::string name;
};

#endif // CUSTOMER_H
