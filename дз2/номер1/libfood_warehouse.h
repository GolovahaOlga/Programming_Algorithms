#pragma once
#include "libproduct.h"
enum class WarehouseType {
    CENTER,
    WEST,
    EAST
};

class Warehouse {
private:
    static const int MAX_PRODUCTS = 1000;
    int id;
    WarehouseType type;
    double longitude;
    double latitude;
    int maxCapacity;
    int totalStock;
    Product* products[MAX_PRODUCTS];
    int productCount;
    
    static int nextId;
    
public:
    Warehouse();
    Warehouse(WarehouseType t, double lon, double lat, int cap);
    Warehouse(const Warehouse& other);
    ~Warehouse();
    
    int getId() const;
    WarehouseType getType() const;
    void setType(WarehouseType t);
    double getLongitude() const;
    void setLongitude(double lon);
    double getLatitude() const;
    void setLatitude(double lat);
    int getMaxCapacity() const;
    void setMaxCapacity(int cap);
    int getTotalStock() const;
    int getProductCount() const;
    
    void generateId();
    double calculateDistance(double productLon, double productLat) const;
    bool updateTotalStock(int quantity, bool add);
    bool addProduct(Product* product);
    bool removeProduct(const char* barcode);
    Product* findProduct(const char* desc) const;
    void listProducts() const;
    const char* warehouseTypeToString() const;
};