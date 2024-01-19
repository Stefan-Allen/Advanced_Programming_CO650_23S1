#include "../Headers/RegularOrder.h"
#include "../Headers/Menu.h"
#include "../Headers/Customer.h"


// Constructor
RegularOrder::RegularOrder(const Menu *menu, const Customer *customer, int quantity, double discount)
    : Order(menu, customer, quantity, discount) {
}

// Detailed displayOrder method for client
std::string RegularOrder::DisplayOrderString() const {
    std::string orderString;

    if (menu) {
        orderString += "Menu Item: " + menu->GetTitle() + "\n";
        orderString += "Customer: " + customer->GetName() + "\n";
        orderString += "Quantity: " + std::to_string(quantity) + "\n";
        orderString += "Discount: " + std::to_string(discount * 100) + "%\n";
        orderString += "Total: $" + std::to_string(CalculateTotal()) + "\n";
        orderString += "------------------------\n";
    }

    return orderString;
}
