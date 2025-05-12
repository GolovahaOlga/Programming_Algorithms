#include "libpolynomials.h"
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
Polynomial::Polynomial() { 
    coefficients=nullptr;
    exponents=nullptr;
    degree=-1;
    termsCount=0;
}

Polynomial::Polynomial(int terms) {
    coefficients = new double[terms]();
    exponents = new int[terms]();
    for (int i = 0; i < terms; ++i) {
        coefficients[i] = 0.0;
        exponents[i] = 0;
    }
    degree=-1;
    termsCount=terms;
}

Polynomial::Polynomial(const Polynomial& other) {
    degree=other.degree;
    termsCount=other.termsCount;
    coefficients = new double[other.termsCount];
    exponents = new int[other.termsCount];
    for (int i = 0; i < termsCount; ++i) {
        coefficients[i] = other.coefficients[i];
        exponents[i] = other.exponents[i];
    }
    
}

Polynomial::~Polynomial() {
    delete[] coefficients;
    delete[] exponents;
}

void Polynomial::setTerm(int index, double coefficient, int exponent) {
    if (index >= 0 && index < termsCount) {
        coefficients[index] = coefficient;
        exponents[index] = exponent;
        updateDegree();
    }
}

double Polynomial::getCoefficient(int index) const {
    if (index >= 0 && index < termsCount) {
        return coefficients[index];
    }
    return 0.0;
}

int Polynomial::getExponent(int index) const {
    if (index >= 0 && index < termsCount) {
        return exponents[index];
    }
    return 0;
}
void Polynomial::print() const {
    for (int i = 0; i < termsCount; ++i) {
        cout<<coefficients[i]<<"x^"<<exponents[i]<<"+";
    }
    cout << '\b' << ' ' << '\b'<<endl;;
}

void Polynomial::updateDegree() {
    degree = -1;
    for (int i = 0; i < termsCount; ++i) {
        if (exponents[i] > degree) {
            degree = exponents[i];
        }
    }
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i < termsCount; ++i) {
        result += coefficients[i] * pow(x, exponents[i]);
    }
    return result;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result(termsCount + other.termsCount);
    
    int i = 0, j = 0, k = 0;
    while (i < termsCount && j < other.termsCount) {
        if (exponents[i] < other.exponents[j]) {
            result.setTerm(k++, coefficients[i], exponents[i]);
            i++;
        } else if (exponents[i] > other.exponents[j]) {
            result.setTerm(k++, other.coefficients[j], other.exponents[j]);
            j++;
        } else {
            result.setTerm(k++, coefficients[i] + other.coefficients[j], exponents[i]);
            i++;
            j++;
        }
    }
    
    while (i < termsCount) {
        result.setTerm(k++, coefficients[i], exponents[i]);
        i++;
    }
    
    while (j < other.termsCount) {
        result.setTerm(k++, other.coefficients[j], other.exponents[j]);
        j++;
    }
    
    result.termsCount = k;
    result.updateDegree();
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result(termsCount + other.termsCount);
    
    int i = 0, j = 0, k = 0;
    while (i < termsCount && j < other.termsCount) {
        if (exponents[i] < other.exponents[j]) {
            result.setTerm(k++, coefficients[i], exponents[i]);
            i++;
        } else if (exponents[i] > other.exponents[j]) {
            result.setTerm(k++, -other.coefficients[j], other.exponents[j]);
            j++;
            } else {
                result.setTerm(k++, coefficients[i] - other.coefficients[j], exponents[i]);
                i++;
                j++;
        }
    }
    
    while (i < termsCount) {
        result.setTerm(k++, coefficients[i], exponents[i]);
        i++;
    }
    
    while (j < other.termsCount) {
        result.setTerm(k++, -other.coefficients[j], other.exponents[j]);
        j++;
    }
    
    result.termsCount = k;
    result.updateDegree();
    return result;
}