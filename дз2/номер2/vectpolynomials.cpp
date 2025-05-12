#include "libvectpolynomials.h"
#include "libpolynomials.h"
#include <iostream>
using namespace std;
VectPolynomial::VectPolynomial() {
    polynomials=nullptr;
    size=0;
}

VectPolynomial::VectPolynomial(int n) {
    size=n;
    polynomials = new Polynomial[n]();
}

VectPolynomial::VectPolynomial(const VectPolynomial& other) {
    size=other.size;
    polynomials = new Polynomial[other.size]();
    for (int i = 0; i < size; ++i) {
        polynomials[i] = other.polynomials[i];
    }
}

VectPolynomial::~VectPolynomial() {
    delete[] polynomials;
}

void VectPolynomial::setPolynomial(int index, const Polynomial& p) {
    if (index >= 0 && index < size) {
        polynomials[index] = p;
    }
}

Polynomial VectPolynomial::getPolynomial(int index) const {
    if (index >= 0 && index < size) {
        return polynomials[index];
    }
    return Polynomial();
}

void VectPolynomial::print() const {
    for (int i = 0; i < size; ++i) {
        cout << "Polynomial " << i << ": ";
        polynomials[i].print();
    }
}

int VectPolynomial::countPolynomials() {
    int count;
    cout << "Enter number of polynomials: ";
    cin >> count;
    return count;
}

VectPolynomial VectPolynomial::processVectors(const VectPolynomial& v1, const VectPolynomial& v2) {
    if (v1.size == 0 || v2.size == 0) {
        std::cerr << "Error: One of the vectors is empty\n";
        return VectPolynomial();
    }
    if (v1.size != v2.size) {
        std::cerr << "Error: Vector sizes don't match (" 
                  << v1.size << " vs " << v2.size << ")\n";
        return VectPolynomial();
    }

    VectPolynomial result(v1.size);

    for (int i = 0; i < v1.size; ++i) {
        if (i % 2 == 0) {
            result.polynomials[i] = v1.polynomials[i] + v2.polynomials[i];
            cout << "Processing even index " << i << ": addition\n";
        } else {
            result.polynomials[i] = v1.polynomials[i] - v2.polynomials[i];
            
        }
        
    }
    cout << "\nSuccessfully processed " << v1.size << " polynomial pairs\n";
    return result;
}