#include "../Headers/Customer.h"
#include "../Headers/Order.h"

// Constructor, Initialize name and email members.
Customer::Customer(const std::string &name, const std::string &email)
    : name(name), email(email) {
}

// Encapsulation, Getter method for name.
std::string Customer::GetName() const {
    return name;
}

// Encapsulation, Getter method for email.
std::string Customer::GetEmail() const {
    return email;
}
