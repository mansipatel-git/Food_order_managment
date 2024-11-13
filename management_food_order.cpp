#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Class to represent a menu item
class MenuItem {
public:
    int id;
    string name;
    double price;

    MenuItem(int id, string name, double price) : id(id), name(name), price(price) {}

    void displayItem() const {
        cout << "ID: " << id << " | " << name << " | Price: $" << price << endl;
    }
};

// Class to represent a single order
class Order {
public:
    int orderId;
    vector<MenuItem> items;
    double totalAmount;

    Order(int orderId) : orderId(orderId), totalAmount(0) {}

    void addItem(MenuItem item) {
        items.push_back(item);
        totalAmount += item.price;
    }

    void displayOrder() const {
        cout << "\nOrder ID: " << orderId << "\nItems:\n";
        for (const auto& item : items) {
            item.displayItem();
        }
        cout << "Total Amount: $" << totalAmount << endl;
    }
};

// Class to manage the menu and orders
class OrderManagement {
private:
    vector<MenuItem> menu;
    vector<Order> orderHistory;
    int nextOrderId;

public:
    OrderManagement() : nextOrderId(1) {}

    // Add an item to the menu
    void addMenuItem(int id, string name, double price) {
        menu.push_back(MenuItem(id, name, price));
    }

    // Display the menu
    void displayMenu() const {
        cout << "\n--- Menu ---\n";
        for (const auto& item : menu) {
            item.displayItem();
        }
    }

    // Place a new order
    void placeOrder() {
        Order newOrder(nextOrderId++);
        int itemId;
        char choice;

        displayMenu();
        cout << "Enter item IDs to add to your order (0 to finish):\n";
        while (true) {
            cout << "Item ID: ";
            cin >> itemId;
            if (itemId == 0) break;

            // Find item by ID and add it to the order
            bool found = false;
            for (const auto& item : menu) {
                if (item.id == itemId) {
                    newOrder.addItem(item);
                    cout << item.name << " added to the order.\n";
                    found = true;
                    break;
                }
            }

            if (!found) cout << "Item not found in menu.\n";
        }

        orderHistory.push_back(newOrder);
        cout << "Order placed successfully! Order ID: " << newOrder.orderId << endl;
    }

    // Display all orders in order history
    void viewOrderHistory() const {
        cout << "\n--- Order History ---\n";
        for (const auto& order : orderHistory) {
            order.displayOrder();
        }
    }

    // Save order history to a file
    void saveOrdersToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& order : orderHistory) {
                file << "Order ID: " << order.orderId << "\n";
                for (const auto& item : order.items) {
                    file << item.id << " " << item.name << " $" << item.price << "\n";
                }
                file << "Total: $" << order.totalAmount << "\n\n";
            }
            file.close();
            cout << "Order history saved to " << filename << endl;
        } else {
            cout << "Failed to open file.\n";
        }
    }
};
int main() {
    OrderManagement system;
    
    // Adding sample menu items
    system.addMenuItem(1, "Burger", 5.99);
    system.addMenuItem(2, "Pizza", 8.99);
    system.addMenuItem(3, "Pasta", 6.99);
    system.addMenuItem(4, "Salad", 4.99);
    
    int choice;
    
    while (true) {
        cout << "\n--- Food Order Management System ---\n";
        cout << "1. Display Menu\n";
        cout << "2. Place Order\n";
        cout << "3. View Order History\n";
        cout << "4. Save Order History to File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.displayMenu();
                break;
            case 2:
                system.placeOrder();
                break;
            case 3:
                system.viewOrderHistory();
                break;
            case 4:
                system.saveOrdersToFile("order_history.txt");
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
