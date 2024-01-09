#include <iostream>
#include "src/MenuItems.h"
#include "src/WinsockClient.h"

int main() {
    // Instances of MenuItems, Menu, Specials, and Customer classes.
    MenuItems menu_items;

    // Adding Menu/Special Instances
    Menu menu1(std::string("Steak"), 19.99);
    Menu menu2(std::string("Beef Burger"), 13.99);
    Menu menu3(std::string("Blueberry Lemonade"), 4.99);

    Specials special1("Special Soup", 9.99);

    // Creating Customer instances
    Customer customer1("John Doe", "john@gmail.com");

    // MenuItems class are called.
    menu_items.AddMenu(menu1);
    menu_items.AddMenu(menu2);
    menu_items.AddMenu(menu3);

    // Specials
    menu_items.AddSpecials(special1);

    // Add customers
    menu_items.AddCustomer(customer1);

    // Overloaded PlaceOrderhandles Menu and Specials objects.
    menu_items.PlaceOrder(menu1, customer1, 1);

    // Displaying the total number of orders and inventory.
    std::cout << "Total Orders: " << menu_items.GetTotalOrders() << "\n";

    // Displaying the inventory of menus and specials.
    menu_items.DisplayInventory();

    // Displaying detailed orders for customers.
    menu_items.DisplayCustomerOrders(customer1);
    menu_items.DisplayOrders(customer1);

    // server's IP address and port.
    WinsockClient winsockClient("127.0.0.1", 3011);

    if (winsockClient.ConnectToServer()) {
        // Orders for customers sent to the server
        std::string customerOrders = menu_items.DisplayOrders(customer1);

        if (winsockClient.SendData(customerOrders)) {
            std::cout << "Orders sent to the server:\n" << customerOrders << std::endl;
        } else {
            std::cerr << "Error sending orders to the server" << std::endl;
        }

        // Connection closed
        winsockClient.CloseConnection();
    }

    return 0;
}
