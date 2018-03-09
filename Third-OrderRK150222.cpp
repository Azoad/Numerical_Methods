#include<bits/stdc++.h>
using namespace std;
double f(double X,double Y)
{
    return -2*pow(X,3)+12*pow(X,2)-20*X+8.5;
}
double equ(double X)
{
    return -.5*pow(X,4)+4*pow(X,3)-10*pow(X,2)+8.5*X+1;
}
main()
{
    double a,b,x,y,h,k1,k2,k3,res=0.0;
    cout<<"Enter the range : ";
    cin>>a>>b;
    cout<<"Enter the initial values : ";
    cin>>x>>y;
    cout<<"Enter the step size : ";
    cin>>h;
    cout<<"X\t\tY\t\tY3rk"<<endl;
    cout<<x<<"\t\t"<<equ(x)<<"\t\t"<<y<<endl;
    for(a;a<b;a+=h)
    {
        k1=f(x,y);
        k2=f(x+1.0/2.0*h,y+1.0/2.0*k1*h);
        k3=f(x+h,y-k1*h+2*k2*h)
        res=y+(1.0/6.0)*(k1+4*k2+k3)*h;
        cout<<x+h<<"\t\t"<<equ(x+h)<<"\t\t"<<res<<endl;
        y=res;
        x=x+h;
    }
}

