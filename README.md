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

// Exception Handling using Exception Classes: The code incorporates a custom Exception class, derived from std::exception, for handling errors in a more structured manner. An example can be seen in the try-catch block within the PlaceOrder method of MenuItems. This Exception class allows for encapsulation of error messages and facilitates a cleaner and more organized approach to error handling throughout the code.

// Winsock Client: The WinsockClient class is explicitly used for communication with a server using Winsock. Example: WinsockClient is used for establishing connections, sending, and receiving data in the main function.

// Winsock Server: The server-side functionality is encapsulated within the WinsockServer class. This class handles the initialization of the Winsock library, binding the server socket to a specific port, and listening for incoming connections. Upon accepting a connection, the server receives and processes data from the connected client, demonstrating a basic server implementation using Winsock.


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

