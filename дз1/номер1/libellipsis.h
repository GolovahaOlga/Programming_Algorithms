#pragma once
class Ellipsis{
    public:
        double h,k,a,b;
        bool d;
    public:
        void replacement();
        Ellipsis();
        Ellipsis(double h1,double k1,double a1,double b1);
        Ellipsis(const Ellipsis &r);
        ~Ellipsis();
        double calculate_c();
        void vertex();
        void focus();
        double focal_chord();
        double eccenticity();
        void set_h(double h);
        double get_h();
        void set_k(double k);
        double get_k();
        void set_a(double a); 
        double get_a(); 
        void set_b(double b); 
        double get_b(); 
};
void ellipse_epuation(Ellipsis e1);
double perimeter(Ellipsis e1);
double square(Ellipsis e1);
void calculateY(double x,Ellipsis e);
void calculateX(double y,Ellipsis e);
