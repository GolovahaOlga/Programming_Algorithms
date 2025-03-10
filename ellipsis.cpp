#include <iostream>
#include <cmath>
#include "libellipsis.h"
using namespace std;
void Ellipsis::replacement(){
    if (b>a){
        do{
            cout<< "Enter new a and b"<<endl;
                cin>>a>>b;
        }while(b>a);       
    }
}
Ellipsis::Ellipsis(){
    h=0;
    k=0;
    a=1;
    b=1;
    replacement();
}
Ellipsis::Ellipsis(double h1,double k1,double a1,double b1){
    h=h1;
    k=k1;
    a=a1;
    b=b1;
    replacement();
}
Ellipsis::Ellipsis(const Ellipsis &r){
    h=r.h;
    k=r.k;
    a=r.a;
    b=r.b;
    replacement();
}
Ellipsis::~Ellipsis(){}
double Ellipsis::calculate_c(){
    double c;
    c=sqrt(pow(a,2)-pow(b,2));
    return c;
}
void Ellipsis::vertex(){
    double V1_x,V1_y,V2_x,V2_y;
    if (d==1){  
        V1_x=h-a;
        V1_y=k;
        V2_x=h+a;
        V2_y=k;
        cout<<"V1 ("<<V1_x<<", "<<V1_y<<") , V1 ("<<V2_x<<", "<<V2_y<<")"<<endl;
    } else { 
        V1_x=h;
        V1_y=k-a;
        V2_x=h;
        V2_y=k+a;
        cout<<"V1 ("<<V1_x<<", "<<V1_y<<") , V1 ("<<V2_x<<", "<<V2_y<<")"<<endl;
    }
}
void Ellipsis::focus(){
    double c=calculate_c();
    double f1_x,f1_y,f2_x,f2_y;
    if (d==1){  
        f1_x=h-c;
        f1_y=k;
        f2_x=h+c;
        f2_y=k;
        cout<< "F1(" << f1_x << ", " << f1_y << "), F2(" << f2_x << ", " << f2_y << ")" <<endl;
    } else { 
        f1_x=h;
        f1_y=k-c;
        f2_x=h;
        f2_y=k+c;
        cout<< "F1(" << f1_x << ", " << f1_y << "), F2(" << f2_x << ", " << f2_y << ")" <<endl;
    }
}
double Ellipsis::focal_chord(){
    double LR;
    LR=(2*pow(b,2))/a;
    return LR;
}
double Ellipsis::eccenticity(){
    double e;
    double c=calculate_c();
    e=c/a;
    return e;
}
void Ellipsis::set_h(double h){
    this->h = h; 
}
double Ellipsis::get_h(){
    return h; 
}
void Ellipsis::set_k(double k){
    this->k = k; 
}
double Ellipsis::get_k(){
    return k; 
}
void Ellipsis::set_a(double a){
    this->a = a; 
    replacement();
}
double Ellipsis::get_a() { 
    return a; 
}
void Ellipsis::set_b(double b){
    this->b = b;
    replacement(); 
}
double Ellipsis::get_b(){
    return b; 
}
void ellipse_epuation(Ellipsis e1){
    if (e1.d==1){
        cout<< "(((x - "<<e1.h<<")^2)/( "<<e1.a<<"^2) + (((y -"<<e1.k<<")^2)/("<<e1.b<<"^2)=1"<<endl;
    }else {
        cout<< "(((x - "<<e1.h<<")^2)/( "<<e1.b<<"^2) + (((y -"<<e1.k<<")^2)/("<<e1.a<<"^2)=1"<<endl;
    }
    cout<<"Centre C("<<e1.h<<";"<<e1.k<<" )"<<endl;
    void vertex();
    void focus();
}
void print_point_position(Ellipsis e1){
    double x,y;
    cout<<"Is the point inside the ellipse? Enter her coordinates"<<endl;
    cout<<"Enter x: "<<endl;
    cin>>x;
    cout<<"Enter y: "<<endl;
    cin>>y;
    if ((pow(x,2))/(pow(e1.a,2))+((pow(y,2)/pow(e1.b,2)))<1){
        cout<<"The point is inside the ellipse"<<endl;
    }else if ((pow(x,2))/(pow(e1.a,2))+((pow(y,2)/pow(e1.b,2)))==1){
        cout<<"The point is located on an ellipse"<<endl;
        }else{
            cout<<"The point is located outside the ellipse"<<endl;
        }
}
double perimeter(Ellipsis e1){
    double P;
    P=M_PI*(3*(e1.a + e1.b)-sqrt((3*e1.a+e1.b)*(e1.a+3*e1.b)));
    return P;
}
double square(Ellipsis e1){
    double S;
    S=M_PI*e1.a*e1.b;
    return S;
}
void calculateY(double x,Ellipsis e){
    double y;
    if (e.d==1){
        y=e.k+sqrt(1/(pow(e.b,2))-((pow((x-e.h),2))/((pow(e.b,2))*(pow(e.a,2)))));
    } else{
        y=e.k+(sqrt(1/(pow(e.a,2))-((pow((x-e.h),2)/((pow(e.a,2))*(pow(e.b,2)))))));
    }
    cout<<y;
}
void calculateX(double y,Ellipsis e){
    double x;
    if(e.d==1){
        x=e.h+sqrt(1/pow(e.a,2)-(pow((y-e.k),2)/(pow(e.b,2)*pow(e.a,2))));
    }else{
        x=e.h+sqrt(1/pow(e.b,2)-(pow((y-e.k),2)/(pow(e.b,2)*pow(e.a,2))));
    }
    cout<<x;
}