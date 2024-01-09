#include "Specials.h"
#include <sstream>
#include <iomanip>


// Constructors, initializing of Specials objects.
Specials::Specials(const std::string &name, double price)
    : name(name), price(price) {
}

// Encapsulation, Get the name of the special item.
std::string Specials::GetName() const {
    return name;
}

// Encapsulation, Get the price of the special item.
double Specials::GetPrice() const {
    return price;
}

// Polymorphic Behaviour through method overloading.
// Provides information about the special item.
std::string Specials::GetInfo() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << price;
    // Return a string containing the name and formatted price.
    return name + ", Price: $" + stream.str();
}
