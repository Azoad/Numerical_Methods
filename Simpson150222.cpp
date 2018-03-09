#include<bits/stdc++.h>
using namespace std;
double f(double X)
{
    return (exp(X)*sin(X))/(1+pow(X, 2));
}
int main()
{
    double a,b,fx0,fx1,fx2,fx3,segment=0.0,value1=0.0,value2=0.0;
    cout<<"The function is : (e^x*sinx)/(1+x^2)"<<endl;
    cout<<"Enter the limits"<<endl;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    segment = (b-a)/2;
    fx0 = f(a);
    fx1 = f(a+segment);
    fx2 = f(b);
    value1 = ((b-a)*(fx0+4*fx1+fx2))/6;
    segment = (b-a)/3;
    fx1 = f(a+segment);
    fx2 = f(a+2*segment);
    fx3 = f(b);
    value2 = ((b-a)*(fx0+3*fx1+3*fx2+fx3))/8;
    cout<<"The value of simpson 1/3 is = "<<value1<<endl;
    cout<<"The value of simpson 3/8 is = "<<value2<<endl;
}
