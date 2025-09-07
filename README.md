# Food-Ordering-1
A console-based mini project that simulates a food ordering and tracking system
# 🍴 Food Ordering System (C++)

This is a *console-based Food Ordering System* implemented in *C++*.  
It simulates a simple restaurant ordering process where the admin can *manage a menu* and customers can *place, cancel, and process orders*.  

The project demonstrates *Data Structures concepts* such as:  
- *Linked List* → Used for Menu management (adding, updating, deleting, searching food items).  
- *Queue* → Used for Order management (placing orders, billing, cancellation, tracking pending orders).  

---

## 📌 Features

### 🔹 Menu Management (Linked List)
- Add new food items with ID, Name, Price, and Rating.
- Update existing items.
- Delete items.
- Search for items.
- Display full menu.

### 🔹 Order Management (Queue)
- Place orders (customers select items by ID).
- Process orders (generate *bill*).
- Cancel orders by ID.
- Display pending orders.
- Generate sales report of the day.

---

## 🛠 Data Structures Used
- **Item Class** → Represents menu items (Node of a Linked List).  
- **Menu Class** → Implements Linked List operations for food items.  
- **Order Class** → Represents customer orders.  
- **Queue Class** → Manages orders using a Queue.  

---

