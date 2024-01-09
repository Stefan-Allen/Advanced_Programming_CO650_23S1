#ifndef SPECIALS_H
#define SPECIALS_H

#include <string>
#include <iomanip>

// The class Specials provides an abstraction for special items.
class Specials {
public:
    // Constructors, Used for initializing the state of Specials objects.
    Specials(const std::string &name, double price);

    // Encapsulate the state of the Specials class.
    std::string GetName() const;

    double GetPrice() const;

    // Polymorphic Behaviour through overloading.
    // Provides information about the special item.
    std::string GetInfo() const;

private:
    // Private members to store name and price of the special item.
    std::string name;
    double price;
};

#endif // SPECIALS_H
