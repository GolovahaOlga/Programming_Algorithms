#include <iostream>
#include <algorithm>
#include <cmath>
#include "libquanternion.h"
using namespace std;
// constructor per default
Quanternion::Quanternion(){
    a=1;
    b=0;
    c=0;
    d=0;
}
// constructor by parameters
Quanternion::Quanternion(double a1, double b1, double c1, double d1){
    a=a1;
    b=b1;
    c=c1;
    d=d1;
}
// constructor by object copy
Quanternion::Quanternion(const Quanternion &r){
    a=r.a;
    b=r.b;
    c=r.c;
    d=r.d;
}
Quanternion::~Quanternion(){}
void Quanternion::set_a(double real){
    a = real; 
}
void Quanternion::set_b(double ib){
    b = ib; 
}
void Quanternion::set_c(double ic){
    c = ic; 
}
void Quanternion::set_d(double id){
    d = id; 
}
double Quanternion::get_a(){
    return a;
}
double Quanternion::get_b(){
    return b;
}
double Quanternion::get_c(){
    return c;
}
double Quanternion::get_d(){
    return d;
}
void print(Quanternion &q){
    cout<<q.a<<"+"<<q.b<<"i+"<<q.c<<"j+"<<q.d<<"k"<<endl;
}
double nq(Quanternion &q){
    double nq;
    nq=sqrt(pow(q.a,2)+pow(q.b,2)+pow(q.c,2)+pow(q.d,2));
    return nq;
}
void sq(Quanternion &q){
    double a1,b1,c1,d1;
    a1=q.a;
    b1=(-1)*(q.b);
    c1=(-1)*(q.c);
    d1=(-1)*(q.d);
    q=Quanternion(a1,b1,c1,d1);
}
void norm(Quanternion &q){
    double nq1=nq(q);
    q=Quanternion((q.a)/nq1,(q.b)/nq1,(q.c)/nq1,(q.d)/nq1);
}
void inv(Quanternion &q){
    Quanternion q1;
    double n=nq(q)*nq(q);
    sq(q);
    q1=Quanternion(q.a/n,q.b/n,q.c/n,q.d/n);
    print(q1);
}
void sum(Quanternion &q1, Quanternion &q2){
    Quanternion q3;
    q3=Quanternion(q1.a+q2.a,q1.b+q2.b,q1.c+q2.c,q1.d+q2.d);
    print(q3);
}
void sub(Quanternion &q1, Quanternion &q2){
    Quanternion q3;
    q3=Quanternion(q1.a-q2.a,q1.b-q2.b,q1.c-q2.c,q1.d-q2.d);
    print(q3);
}
void multiplication(Quanternion &q1, Quanternion &q2){
    Quanternion q3;
    q3=Quanternion(q1.a*q2.a,q1.b*q2.b,q1.c*q2.c,q1.d*q2.d);
    print(q3);
}
void division(Quanternion &q1, Quanternion &q2){
    Quanternion q3;
    q3=Quanternion((q1.a)/(q2.a),(q1.b)/(q2.b),(q1.c)/(q2.c),(q1.d)/(q2.d));
    print(q3);
}
double scalar_product(Quanternion &q1, Quanternion &q2){
    double s;
    s=q1.a*q2.a+q1.b*q2.b+q1.c*q2.c+q1.d*q2.d;
    return s;
}
double Euclidean_distance(Quanternion &q1, Quanternion &q2){
    double s;
    s=sqrt(pow((q1.a-q2.a),2)+pow((q1.b-q2.b),2)+pow((q1.c-q2.c),2)+pow((q1.d-q2.d),2));
    return s;
}
double max( double a, double b, double c, double d){
    double big=a;
    if (b>big){
        b=big;
    }
    if(c>big){
        c=big;
    }
    if(d>big){
        d=big;
    }
    return big;
}
double normch(Quanternion &q1, Quanternion &q2){
    double s,a1,b1,c1,d1;
    a1=abs(q1.a-q2.a);
    b1=abs(q1.b-q2.b);
    c1=abs(q1.c-q2.c);
    d1=abs(q1.d-q2.d);
    s=max(a1,b1,c1,d1);
    return s;
}