#include "Menu.h"
// Constructors initialize title, price, and name members.
Menu::Menu(const std::string &title, double price)
    : title(title), price(price) {
}

Menu::Menu(const std::string &name)
    : name(name) {
}

// Getter to retrieve title of the menu item.
std::string Menu::GetTitle() const {
    return title;
}

// Getter to retrieves price of the menu item.
double Menu::GetPrice() const {
    return price;
}

// Getter to retrieve the name of the menu item.
std::string Menu::GetName() const {
    return name;
}

// Abstraction, Provides information about the menu item.
std::string Menu::GetInfo() const {
    // Format the price.
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << price;
    // string containing the title, formatted price.
    return title + ", Price: $" + stream.str();
}
