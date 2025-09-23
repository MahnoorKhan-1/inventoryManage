#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

struct Item 
{
    string name;
    int quantity;
    double price;
};

void addItem(Item inventory[], int &count) 
{
    if (count >= MAX_ITEMS) 
    {
        cout << "Inventory full, cannot add more items.\n";
        return;
    }
    cout << "Enter item name: ";
    cin >> inventory[count].name;
    cout << "Enter quantity: ";
    cin >> inventory[count].quantity;
    cout << "Enter price: ";
    cin >> inventory[count].price;
    count++;
    cout << "Item added successfully!\n";
}

void displayInventory(Item inventory[], int count)
 {
    cout << "\n--- Inventory List ---\n";
    for (int i = 0; i < count; i++) {
        cout << i+1 << ". " << inventory[i].name 
             << " | Quantity: " << inventory[i].quantity 
             << " | Price: $" << inventory[i].price << "\n";
    }
    cout << "----------------------\n";
}

void searchItem(Item inventory[], int count) {
    string searchName;
    cout << "Enter item name to search: ";
    cin >> searchName;
    for (int i = 0; i < count; i++) {
        if (inventory[i].name == searchName) {
            cout << "Found: " << inventory[i].name 
                 << " | Quantity: " << inventory[i].quantity 
                 << " | Price: $" << inventory[i].price << "\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void deleteItem(Item inventory[], int &count) {
    string deleteName;
    cout << "Enter item name to delete: ";
    cin >> deleteName;
    for (int i = 0; i < count; i++) {
        if (inventory[i].name == deleteName) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            cout << "Item deleted successfully.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

int main() {
    Item inventory[MAX_ITEMS];
    int count = 0;
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Display Inventory\n";
        cout << "3. Search Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(inventory, count); break;
            case 2: displayInventory(inventory, count); break;
            case 3: searchItem(inventory, count); break;
            case 4: deleteItem(inventory, count); break;
            case 5: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
