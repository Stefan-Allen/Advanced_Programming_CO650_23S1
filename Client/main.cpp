#include <iostream>
#include "src/Headers/MenuItems.h"
#include "src/Headers/WinsockClient.h"
#include "src/Headers/RegularOrder.h"
#include "src/Headers/Order.h"

int main() {
    // Instances of MenuItems, Menu, Specials, and Customer classes.
    MenuItems menu_items;

    // Creating Customer instances
    Customer customer1("John Doe", "john@gmail.com");

    // Adding Menu/Special Instances
    Menu menu1(std::string("Steak"), 19.99);
    Menu menu2(std::string("Beef Burger"), 13.99);
    Menu menu3(std::string("Blueberry Lemonade"), 4.99);

    Specials special1("Special Soup", 9.99);

    // MenuItems class are called.
    menu_items.AddMenu(menu1);
    menu_items.AddMenu(menu2);
    menu_items.AddMenu(menu3);

    // Specials
    menu_items.AddSpecials(special1);

    // Add customers
    menu_items.AddCustomer(customer1);

    // Overloaded PlaceOrder handles Menu and Specials objects.
    menu_items.PlaceOrder(menu1, customer1, 1);

    // Inheritance: RegularOrder inheriting from Order.
    std::unique_ptr<RegularOrder> regularOrder = std::make_unique<RegularOrder>(&menu1, &customer1, 1, 0.05);

    // Displaying the total number of orders and inventory.
    std::cout << "------------------------\nTotal Orders: " << menu_items.GetTotalOrders() << "\n" "------------------------\n";

    // Add the RegularOrder to the vector of orders
    Order::GetOrders().emplace_back(regularOrder.get());

    // Explicitly using RegularOrder methods
    std::cout << "RegularOrder Details:\n";
    std::cout << regularOrder->DisplayOrderString();
    std::cout << "Calculated Total: $" << regularOrder->CalculateTotal() << "\n";

    // server's IP address and port.
    WinsockClient winsockClient("127.0.0.1", 3011);

    if (winsockClient.ConnectToServer()) {
        // Orders for customers sent to the server
        std::string customerOrders = menu_items.DisplayOrders(customer1);

        if (winsockClient.SendData(customerOrders)) {
            std::cout << "------------------------\nOrders sent to the server successfully.\n";
        } else {
            std::cerr << "Error sending orders to the server" << std::endl;
        }

        // Connection closed
        winsockClient.CloseConnection();
    }

    return 0;
}