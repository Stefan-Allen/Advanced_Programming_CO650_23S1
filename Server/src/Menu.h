#ifndef MENU_H
#define MENU_H

#pragma once
#include <string>
#include <iomanip>

// Abstraction, Represents a menu item with a title and price.
class Menu {
public:
    // Constructors that initialize title, price, and name members.
    Menu(const std::string &title, double price);

    Menu(const std::string &name);

    // Getter for retrieving the title, price, and name of the menu item.
    std::string GetTitle() const;

    double GetPrice() const;

    std::string GetName() const;

    std::string GetInfo() const; // Abstraction providing information about the menu item.

private:
    // Encapsulation, to store the title, price, and name of the menu item.
    std::string title;
    double price;
    std::string name;
};

#endif // MENU_H
