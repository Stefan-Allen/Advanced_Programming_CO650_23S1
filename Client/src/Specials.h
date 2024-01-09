#ifndef SPECIALS_H
#define SPECIALS_H

#include <string>
#include <iomanip>

// Abstraction, Specials provides an abstraction for representing special items.
// Encapsulation, Private members to encapsulate state of Specials class.
class Specials {
public:
    // Constructor, Used for initializing the state of Specials objects.
    Specials(const std::string &name, double price);

    // Encapsulation, Private members to encapsulate the state of the Specials class.
    std::string GetName() const;

    double GetPrice() const;

    // Polymorphic Behaviour through method overloading.
    // Provides information about the special item.
    std::string GetInfo() const;

private:
    // Private members to store the name and price of the special item.
    std::string name;
    double price;
};

#endif // SPECIALS_H
