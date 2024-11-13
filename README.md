# Food Order Management System

This project is a console-based **Food Order Management System** implemented in C++. It allows users to view a menu, place an order, view order history, and save order history to a file.

## Table of Contents
- [Features](#features)
- [Classes and Functions](#classes-and-functions)
- [How to Use](#how-to-use)
- [Code Structure](#code-structure)
- [Example Usage](#example-usage)

---

## Features

- Display a menu with items, each with a unique ID, name, and price.
- Place an order by selecting items from the menu.
- View order history, which shows details of each placed order.
- Save order history to a file for record-keeping.

---

## Classes and Functions

### 1. `MenuItem` Class
Represents an item in the menu.

- **Attributes:**
  - `id`: Unique identifier for the item.
  - `name`: Name of the menu item.
  - `price`: Price of the menu item.
- **Methods:**
  - `displayItem()`: Displays the item's details in a readable format.

### 2. `Order` Class
Represents a single order containing multiple `MenuItem` objects.

- **Attributes:**
  - `orderId`: Unique identifier for the order.
  - `items`: List of items in the order.
  - `totalAmount`: Total cost of the order.
- **Methods:**
  - `addItem(MenuItem item)`: Adds a `MenuItem` to the order and updates the total cost.
  - `displayOrder()`: Displays all items in the order with the total amount.

### 3. `OrderManagement` Class
Handles all operations related to menu and order management.

- **Attributes:**
  - `menu`: List of available `MenuItem` objects.
  - `orderHistory`: List of all completed `Order` objects.
  - `nextOrderId`: Tracks the ID for the next order.
- **Methods:**
  - `addMenuItem(int id, string name, double price)`: Adds a new item to the menu.
  - `displayMenu()`: Displays all available items in the menu.
  - `placeOrder()`: Allows the user to place a new order by selecting items from the menu.
  - `viewOrderHistory()`: Displays all orders placed so far.
  - `saveOrdersToFile(const string& filename)`: Saves all orders to a specified file.

---

## How to Use

1. **Display the Menu**:
   Choose this option to see all available items and their prices.
   
2. **Place an Order**:
   Select this option to add items to an order. You can keep adding items until you enter `0` to finalize the order.

3. **View Order History**:
   Displays all previously placed orders along with their item details and total cost.

4. **Save Order History to File**:
   Saves the order history to a file named `order_history.txt`.

5. **Exit**:
   Exits the program.

---

## Code Structure

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
```
## Example Usage
**Display Menu**
--- Menu ---
ID: 1 | Burger | Price: $5.99
ID: 2 | Pizza | Price: $8.99
ID: 3 | Pasta | Price: $6.99
ID: 4 | Salad | Price: $4.99
