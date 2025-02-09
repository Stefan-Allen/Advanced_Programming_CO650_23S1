#ifndef MENU_H
#define MENU_H

#pragma once
#include <string>
#include <iomanip>
#include <sstream>

// Abstraction
class Menu {
public:
    // Constructors
    Menu(const std::string &title, double price);

    // Encapsulation, Getter methods to access private data members.
    std::string GetTitle() const;

    double GetPrice() const;

    // Polymorphic Behaviour, Getter method for information, overloaded for Menu class
    std::string GetInfo() const;

private:
    // Encapsulation, Private data members
    std::string title;
    double price;
};

#endif // MENU_H
