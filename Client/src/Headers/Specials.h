#ifndef SPECIALS_H
#define SPECIALS_H

#include <string>
#include <iomanip>

// Abstraction
class Specials {
public:
    // Constructors
    Specials(const std::string &name, double price);

    // Encapsulation
    std::string GetName() const;

    double GetPrice() const;

    // Polymorphic Behaviour through method overloading.
    virtual std::string GetInfo() const;

private:
    std::string name;
    double price;
};

#endif // SPECIALS_H
