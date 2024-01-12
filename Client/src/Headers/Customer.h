#ifndef CUSTOMER_H
#define CUSTOMER_H

#pragma once
#include <string>

// Abstraction, Representing a customer with a name and email.
class Customer {
public:
    // Constructors
    Customer(const std::string &name, const std::string &email);

    // Encapsulation, Getter methods to access private data members.
    std::string GetName() const;

    std::string GetEmail() const;

private:
    // Encapsulation, Private data members
    std::string name;
    std::string email;
};

#endif // CUSTOMER_H