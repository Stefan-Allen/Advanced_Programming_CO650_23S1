#include "../Headers/Menu.h"

// Constructors initialize title and price members.
Menu::Menu(const std::string &title, double price)
    : title(title), price(price) {
}

// Encapsulation: Getter method for title
std::string Menu::GetTitle() const {
    return title;
}

// Encapsulation: Getter method for price
double Menu::GetPrice() const {
    return price;
}

// Polymorphic Behaviour: Getter method for information, overloaded for Menu class
std::string Menu::GetInfo() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << price;
    return title + ", Price: $" + stream.str();
}