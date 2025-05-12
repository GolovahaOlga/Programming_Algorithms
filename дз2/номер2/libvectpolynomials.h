#pragma once
#include "libpolynomials.h"
class VectPolynomial {
    private:
        Polynomial* polynomials;
        int size;

    public:
        VectPolynomial();
        VectPolynomial(int size);
        VectPolynomial(const VectPolynomial& other);
        ~VectPolynomial();
        void setPolynomial(int index, const Polynomial& p);
        Polynomial getPolynomial(int index) const;
        void print() const;
        int getSize() const { return size; }
        static int countPolynomials();
        static VectPolynomial processVectors(const VectPolynomial& v1, const VectPolynomial& v2);
};