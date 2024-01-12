Made using Clion, CMakeLists.txt is the configuration file used by CMake to build the project, CLion triggers the CMake to generates native build files (e.g., Makefiles on Unix-like systems, Visual Studio project files on Windows) based on the information in CMakeLists.txt.

// Abstraction: Used throughout the program, notably in the MenuItems class, which abstracts the details of handling menus, specials, customers, and orders.

// Encapsulation: Utilized in various classes, such as Customer, Menu, MenuItems, Order, and its subclasses, where private data members and getter methods encapsulate the internal state of objects.

// Inheritance: Demonstrated in RegularOrder inheriting from Order and DiscountedOrder inheriting from Order.

// Polymorphic Behaviour: Implemented through virtual functions and method overloads in various classes, such as Order and its subclasses.

// Overloading: Overloaded methods in the MenuItems class for handling different types of objects and displaying orders.

// Friendship: Friendship is used between the MenuItems class and the Order class.

// Static Members: Utilized in the MenuItems class with the totalOrders member.

// Constructors: Constructors are used in various classes to initialize objects. Example: Customer, Menu, WinsockClient, etc.

// Pointers: Pointers are used in several places for dynamic memory allocation and handling objects. Example: std::unique_ptr in MenuItems.

// Functional Pointers: The OrderProcessor is a functional pointer used in the MenuItems class for processing orders.

// Exception Handling using Exception Classes (Inheriting from Exception): Exception handling is implemented with the OrderException class, inheriting from std::exception. Example: try-catch block in PlaceOrder method of MenuItems.

// Winsock Client: The WinsockClient class is explicitly used for communication with a server using Winsock. Example: WinsockClient is used for establishing connections, sending, and receiving data in the main function.

CLIENT CONSOLE 

C:\Users\Tig10\Documents\GitHub\Advanced_Programming_CO650_23S1\Client\cmake-build-debug\Client.exe
------------------------
Total Orders: 1
------------------------
RegularOrder Details:
Menu Item: Steak
Customer: John Doe
Quantity: 1
Discount: 5.000000%
Total: $17.991000
------------------------
Calculated Total: $17.991
------------------------
Orders sent to the server successfully.

Process finished with exit code 0


SERVER CONSOLE 

C:\Users\Tig10\Documents\GitHub\Advanced_Programming_CO650_23S1\Server\cmake-build-debug\Server.exe
Successful
------------------------
Client connected
------------------------
Received order: Orders for Customer: John Doe
Customer: John Doe
Discount: 5.000000%
Total: $18.990500
------------------------

