#include <iostream>
#include <cmath>
#include "libellipsis.h"
#include "ellipsis.cpp"
using namespace std;
int main(){
    double h,k,a,b,d;
    double x,y;
    int r;
    Ellipsis e1,e2;
    e1=Ellipsis();
    cout<<"Enter the coordinates of the center of the ellipse, the length of the major and minor semi-axes, specify 1 if the semimajor axis is on the x axis "<<endl;
    cout<<"h :"<<endl;
    cin>>h;
    cout<<"k :"<<endl;
    cin>>k;
    cout<<"a :"<<endl;
    cin>>a;
    cout<<"b :"<<endl;
    cin>>b;
    cout<<"d :"<<endl;
    cin>>d;
    e2=Ellipsis(h,k,a,b);
    cout<<"Hyperparameter of ellipsis 2 : "<<e2.calculate_c()<<endl;
    e2.vertex();
    e2.focus();
    e2.focal_chord();
    e2.eccenticity();
    ellipse_epuation(e2);

    print_point_position(e1);

    cout<<"Perimeter: "<<perimeter(e2)<<endl;
    cout<<"Square: "<<square(e2)<<endl;
    cout<<"If you know the x coordinate, enter 1, else 0"<<endl;
    cin>>r;
    if (r==1){
        cout<<"Enter x"<<endl;
        cin>>x;
        cout<<"Y: "<<endl;
        calculateY(x,e2);
    }else if(r==0){
        cout<<"Enter y"<<endl;
        cin>>y;
        cout<<"X: "<<endl;
        calculateX(y,e2);
    }
    return 0;
}