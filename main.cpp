#include <iostream>
#include <cmath>
#include "libquanternion.h"
#include "quanternion.cpp"
using namespace std;
int main(){
    int h;
    double a1,b1,c1,d1;
    Quanternion q1, q2, q3,q4;
    cout<<"---Quanternion 01 --- "<<endl; 
    // creat object by def
    q1=Quanternion();
    print(q1);
    cout<<"---Quanternion 02 --- "<<endl; 
    cout<<"Enter the real part of the number and the real coefficients for imaginary numbers."<<endl;
    cout<<"a: "<<endl;
    cin>>a1;
    cout<<"b: "<<endl;
    cin>>b1;
    cout<<"c: "<<endl;
    cin>>c1;
    cout<<"d: "<<endl;
    cin>>d1;
    q2=Quanternion(a1,b1,c1,d1);
    print(q2);
    do{
        cout<<"Enter 1 if you want to copy the first quanternion. Enter 2 if you want to copy the second quanternion."<<endl;
        cin>>h;
    }while(h!=1 and h!=2);
    if (h==1){
        cout<<"---Quanternion 03 = Quanternion 01--- "<<endl; 
        q3=Quanternion(q1);
        print(q3);
    }else if (h==2){
        cout<<"---Quanternion 03 = Quanternion 02--- "<<endl; 
        q3=Quanternion(q2);
        print(q3);
    }
    cout<<"Calculating the quaternion 01 norm: "<<nq(q1)<<endl;
    cout<<"Conjugate quaternion 02: "<< endl;
    q4=q2;
    sq(q4);
    print(q4);
    cout<<"Normalization of the quaternion 01: "<<endl;
    q4=q1;
    norm(q4);
    print(q4);
    cout<<"Inversion of the quaternion 02: "<<endl;
    inv(q2);
    cout<<"Quanternion 01 + Quanternion 02 = "<<endl;
    sum(q1,q2);
    cout<<"Quanternion 01 - Quanternion 02 = "<<endl;
    sub(q1,q2);
    cout<<"Quanternion 01 * Quanternion 02 = "<<endl;
    multiplication(q1,q2);
    cout<<"Quanternion 01 / Quanternion 02 = "<<endl;
    division(q1,q2);
    cout<<"The scalar product Quanternion 01 and Quanternion 02 : " << scalar_product(q1,q2)<<endl;
    cout<<"the Euclidean distance between Quanternion 01 and Quanternion 02 : "<<Euclidean_distance(q1,q2)<<endl;
    cout<<"Chebyshev norms between Quanternion 01 and Quanternion 02 : "<<normch(q1,q2)<<endl;
    return 0;
}
