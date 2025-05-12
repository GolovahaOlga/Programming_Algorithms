
#include "libvectpolynomials.h"
#include "libpolynomials.h"
#include "vectpolynomials.cpp"
#include "polynomials.cpp"
#include <iostream>
using namespace std;
int main() {
    int count ;
    cout<<"Enter number of polynomials in vectors: "<<endl;
    cin>>count;
    VectPolynomial V1(count), V2(count);
    cout << "\n=== Enter polynomials for V1 ===\n";
    for (int i = 0; i < count; ++i) {
        int degree;
        cout << "Enter the degree of the polynomial" << i + 1 << " (V1): ";
        cin >> degree;

        Polynomial p1(degree);
        for (int j = 0; j < degree; ++j) {
            double coeff;
            int exp;
            cout << "Enter coefficient and exponent for term " << j << " (e.g., 2 3 for 2x^3): ";
            cin >> coeff >> exp;
            p1.setTerm(j, coeff, exp);
        }
        V1.setPolynomial(i, p1);
    }
    cout << "\n=== Enter polynomials for V2 ===\n";
    for (int i = 0; i < count; ++i) {
        int degree;
        cout << "Enter the degree of the polynomial" << i + 1 << " (V2): ";
        cin >> degree;

        Polynomial p2(degree);
        for (int j = 0; j < degree; ++j) {
            double coeff;
            int exp;
            cout << "Enter coefficient and exponent for term " << j << " (e.g., 2 3 for 2x^3): ";
            cin >> coeff >> exp;
            p2.setTerm(j, coeff, exp);
        }
        V2.setPolynomial(i, p2);
    }
    cout << "\n=== Resulting vectors ===" << endl;
    cout << "V1:\n"; V1.print();
    cout << "V2:\n"; V2.print();
    VectPolynomial vout ;
    double x;
    cout << "\nEnter value of x to evaluate polynomials: ";
    cin >> x;
    vout=vout.processVectors(V1, V2);
    cout << "\nEvaluated results:\n";
    for (int i = 0; i < vout.getSize(); ++i) {
        cout << "Polynomial " << i << " value: " << vout.getPolynomial(i).evaluate(x) << endl;
    }
    cout << "\nVout (result):\n";
    vout.print();
    return 0;
}
