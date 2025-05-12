#pragma once

class Product {
private:
    char* barcode;
    char* description;
    double price;
    int quantity;
    double longitude;
    double latitude;

    void copyString(char*& dest, const char* src);

public:
    Product();
    Product(const char* desc, double pr, int qty, double lon, double lat);
    Product(const Product& other);
    ~Product();
    
    const char* getBarcode() const;
    void setBarcode(const char* code);
    
    const char* getDescription() const;
    void setDescription(const char* desc);
    
    double getPrice() const;
    void setPrice(double pr);
    
    int getQuantity() const;
    void setQuantity(int qty);
    
    double getLongitude() const;
    void setLongitude(double lon);
    
    double getLatitude() const;
    void setLatitude(double lat);
    
    void generateBarcode();
    void print() const;
};