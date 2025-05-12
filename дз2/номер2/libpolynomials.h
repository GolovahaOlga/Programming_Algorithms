#pragma once
class Polynomial {
    private:
        double* coefficients;
        int* exponents;
        int degree;
        int termsCount;

    public:
        Polynomial();
        Polynomial(int terms);
        Polynomial(const Polynomial& other);
        ~Polynomial();
        void setTerm(int index, double coefficient, int exponent);
        double getCoefficient(int index) const;
        int getExponent(int index) const;
        void print() const;
        int getDegree() const { return degree; }
        int getTermsCount() const { return termsCount; }
        double evaluate(double x) const;
        Polynomial operator+(const Polynomial& other) const;
        Polynomial operator-(const Polynomial& other) const;

    private:
        void updateDegree();
};