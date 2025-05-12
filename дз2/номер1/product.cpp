#include "libproduct.h"
#include <random>
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;


void Product::copyString(char*& dest, const char* src) {
    if (dest) delete[] dest;
    if (src) {
        dest = new char[strlen(src) + 1];
        strcpy(dest, src);
    } else {
        dest = nullptr;
    }
}

Product::Product() : barcode(nullptr), description(nullptr), price(0.0), 
                    quantity(0), longitude(0.0), latitude(0.0) {}

Product::Product(const char* desc, double pr, int qty, double lon, double lat) : 
    price(pr), quantity(qty), longitude(lon), latitude(lat) {
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
    generateBarcode();
}

Product::Product(const Product& other) {
    copyString(barcode, other.barcode);
    copyString(description, other.description);
    price = other.price;
    quantity = other.quantity;
    longitude = other.longitude;
    latitude = other.latitude;
}

Product::~Product() {
    delete[] barcode;
    delete[] description;
}

const char* Product::getBarcode() const { return barcode; }
void Product::setBarcode(const char* code) { 
    copyString(barcode, code);
}

const char* Product::getDescription() const { return description; }
void Product::setDescription(const char* desc) { 
    copyString(description, desc);
}

double Product::getPrice() const { return price; }
void Product::setPrice(double pr) { price = pr; }

int Product::getQuantity() const { return quantity; }
void Product::setQuantity(int qty) { quantity = qty; }

double Product::getLongitude() const { return longitude; }
void Product::setLongitude(double lon) { longitude = lon; }

double Product::getLatitude() const { return latitude; }
void Product::setLatitude(double lat) { latitude = lat; }

void Product::generateBarcode() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> part1(1, 9);
    uniform_int_distribution<> part2(0, 999999);
    
    int firstPart = part1(gen) * 1000;
    int secondPart = part2(gen);
    
    char temp[20];
    snprintf(temp, sizeof(temp), "460%d%06d", firstPart, secondPart);
    temp[13] = '\0';
    
    copyString(barcode, temp);
}

void Product::print() const {
    cout << "Barcode:" << (barcode ? barcode : "") << endl;
    cout << "Description:" << (description ? description : "") << endl;
    cout << "Price: " << price << " rub." << endl;
    cout << "Quantity:" << quantity << endl;
    cout << "Coordinates (longitude, latitude): (" << longitude << ", " << latitude << ")" << endl;
}