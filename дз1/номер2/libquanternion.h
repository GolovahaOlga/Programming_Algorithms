#pragma once
class Quanternion{
    public:
        double a,b,c,d;
    public:
        Quanternion();
        Quanternion(double a1, double b1, double c1, double d1);
        Quanternion(const Quanternion &r);
        ~Quanternion();
        void set_a(double real);
        void set_b(double ib);
        void set_c(double ic);
        void set_d(double id);
        double get_a();
        double get_b();
        double get_c();
        double get_d(); 
};
void print(Quanternion &q);
double nq(Quanternion &q);
void sq(Quanternion &q);
void norm(Quanternion &q);
void inv(Quanternion &q);
void sum(Quanternion &q1, Quanternion &q2);
void sub(Quanternion &q1, Quanternion &q2);
void multiplication(Quanternion &q1, Quanternion &q2);
void division(Quanternion &q1, Quanternion &q2);
double scalar_product(Quanternion &q1, Quanternion &q2);
double Euclidean_distance(Quanternion &q1, Quanternion &q2);
double max(double a,double b,double c,double d);
double normch(Quanternion &q1, Quanternion &q2);