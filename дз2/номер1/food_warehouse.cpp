#include "libfood_warehouse.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int Warehouse::nextId = 100;

Warehouse::Warehouse() : id(0), type(WarehouseType::CENTER), longitude(0.0), latitude(0.0), 
                        maxCapacity(0), totalStock(0), productCount(0) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i] = nullptr;
    }
}

Warehouse::Warehouse(WarehouseType t, double lon, double lat, int cap) : 
    type(t), longitude(lon), latitude(lat), maxCapacity(cap), totalStock(0), productCount(0) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i] = nullptr;
    }
    generateId();
}

Warehouse::Warehouse(const Warehouse& other) : 
    id(other.id), type(other.type), longitude(other.longitude), latitude(other.latitude),
    maxCapacity(other.maxCapacity), totalStock(other.totalStock), productCount(other.productCount) {
    
    for (int i = 0; i < productCount; i++) {
        products[i] = new Product(*other.products[i]);
    }
    
    for (int i = productCount; i < MAX_PRODUCTS; i++) {
        products[i] = nullptr;
    }
}

Warehouse::~Warehouse() {
    for (int i = 0; i < productCount; i++) {
        delete products[i];
    }
}

int Warehouse::getId() const { return id; }
WarehouseType Warehouse::getType() const { return type; }
void Warehouse::setType(WarehouseType t) { type = t; }

double Warehouse::getLongitude() const { return longitude; }
void Warehouse::setLongitude(double lon) { longitude = lon; }

double Warehouse::getLatitude() const { return latitude; }
void Warehouse::setLatitude(double lat) { latitude = lat; }

int Warehouse::getMaxCapacity() const { return maxCapacity; }
void Warehouse::setMaxCapacity(int cap) { maxCapacity = cap; }

int Warehouse::getTotalStock() const { return totalStock; }
int Warehouse::getProductCount() const { return productCount; }

void Warehouse::generateId() {
    id = nextId++;
}

double Warehouse::calculateDistance(double productLon, double productLat) const {
    return abs(latitude - productLat) + abs(longitude - productLon);
}

bool Warehouse::updateTotalStock(int quantity, bool add) {
    if (add) {
        if (totalStock + quantity > maxCapacity) return false;
        totalStock += quantity;
    } else {
        if (totalStock - quantity < 0) return false;
        totalStock -= quantity;
    }
    return true;
}

bool Warehouse::addProduct(Product* product) {
    if (productCount >= MAX_PRODUCTS || !updateTotalStock(product->getQuantity(), true)) {
        return false;
    }
    products[productCount++] = product;
    return true;
}

bool Warehouse::removeProduct(const char* barcode) {
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i]->getBarcode(), barcode) == 0) {
            if (!updateTotalStock(products[i]->getQuantity(), false)) {
                return false;
            }
            
            delete products[i];
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            products[--productCount] = nullptr;
            return true;
        }
    }
    return false;
}

Product* Warehouse::findProduct(const char* desc) const {
    for (int i = 0; i < productCount; i++) {
        if (strstr(products[i]->getDescription(), desc) != nullptr) {
            return products[i];
        }
    }
    return nullptr;
}

void Warehouse::listProducts() const {
    cout << "Warehouse #" << id << " (" << warehouseTypeToString() << ")" << endl;
    cout << "Coordinates: (" << longitude << ", " << latitude << ")" << endl;
    cout << "Fullness:" << totalStock << "/" << maxCapacity << endl;
    cout << "List of products:" << endl;
    
    for (int i = 0; i < productCount; i++) {
        products[i]->print();
        cout << "-------------------" << endl;
    }
}
const char* Warehouse::warehouseTypeToString() const {
    switch(type) {
        case WarehouseType::CENTER: return "Center";
        case WarehouseType::WEST: return "The West";
        case WarehouseType::EAST: return "East";
        default: return "Unknown";
    }
}