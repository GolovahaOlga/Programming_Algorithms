#include "libfood_warehouse.h"
#include "libproduct.h"
#include "food_warehouse.cpp"
#include "product.cpp"
#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

void displayMenu() {
    cout << "\nWarehouse Management Menu:\n";
    cout << "1. Add a product\n";
    cout << "2. Show all products in stock\n";
    cout << "3. Find the product by description\n";
    cout << "4. Delete a product\n";
    cout << "5. Exit\n";
    cout << "Select an action: ";
}

Warehouse* selectWarehouse(Warehouse warehouses[], int count, double lon, double lat) {
    Warehouse* selected = nullptr;
    double minDistance = numeric_limits<double>::max();
    
    for (int i = 0; i < count; i++) {
        double distance = warehouses[i].calculateDistance(lon, lat);
        if (distance < minDistance) {
            minDistance = distance;
            selected = &warehouses[i];
        }
    }
    return selected;
}

int main() {
    const int WAREHOUSE_COUNT = 3;
    Warehouse warehouses[WAREHOUSE_COUNT] = {
        Warehouse(WarehouseType::CENTER, 55.75, 37.62, 1000),
        Warehouse(WarehouseType::WEST, 59.94, 30.31, 800),
        Warehouse(WarehouseType::EAST, 56.83, 60.60, 900)
    };
    
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                char desc[51];
                double price, lon, lat;
                int quantity;
                
                cout << "Enter the product description (up to 50 characters):";
                cin.getline(desc, 51);
                cout << "Enter the price:";
                cin >> price;
                cout << "Enter the quantity:";
                cin >> quantity;
                cout << "Enter the longitude of the starting point (19-169):";
                cin >> lon;
                cout << "Enter the latitude of the departure point (41-82):";
                cin >> lat;
                
                Product* newProduct = new Product(desc, price, quantity, lon, lat);
                Warehouse* targetWarehouse = selectWarehouse(warehouses, WAREHOUSE_COUNT, lon, lat);
                
                if (targetWarehouse && targetWarehouse->addProduct(newProduct)) {
                    cout << "The product was successfully added to the warehouse #" << targetWarehouse->getId() << endl;
                } else {
                    cout << "Couldn't add the product. Perhaps the warehouse is full." << endl;
                    delete newProduct;
                }
                break;
            }
            case 2: {
                cout << "Select a warehouse (1-Center, 2-West, 3-East):";
                int warehouseChoice;
                cin >> warehouseChoice;
                
                if (warehouseChoice >= 1 && warehouseChoice <= WAREHOUSE_COUNT) {
                    warehouses[warehouseChoice-1].listProducts();
                } else {
                    cout << "Wrong choice of warehouse." << endl;
                }
                break;
            }
            case 3: {
                char searchTerm[51];
                cout << "Enter part of the search description (up to 50 characters): ";
                cin.getline(searchTerm, 51);
                
                bool found = false;
                for (int i = 0; i < WAREHOUSE_COUNT; i++) {
                    Product* result = warehouses[i].findProduct(searchTerm);
                    if (result != nullptr) {
                        found = true;
                        cout << "Found in the warehouse #" << warehouses[i].getId() << ":" << endl;
                        result->print();
                        cout << "-------------------" << endl;
                    }
                }
                
                if (!found) {
                    cout << "No products were found." << endl;
                }
break;
            }
            case 4: {
                char barcode[14];
                cout << "Enter the barcode of the product to delete (13 characters):";
                cin.getline(barcode, 14);
                
                bool removed = false;
                for (int i = 0; i < WAREHOUSE_COUNT; i++) {
                    if (warehouses[i].removeProduct(barcode)) {
                        cout << "The product has been removed from the warehouse #" << warehouses[i].getId() << endl;
                        removed = true;
                        break;
                    }
                }
                
                if (!removed) {
                    cout << "No product with this barcode was found." << endl;
                }
                break;
            }
            case 5:
                cout << "Exit the program." << endl;
                break;
            default:
                cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}