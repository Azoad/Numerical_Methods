#include<bits/stdc++.h>
using namespace std;
double f(double X,double Y)
{
    return (1+2*X)*pow(Y,.5);
}
/*double equ(double X)
{
    return -.5*pow(X,4)+4*pow(X,3)-10*pow(X,2)+8.5*X+1;
}*/
main()
{
    double a,b,x,y,h,k1,k2,k3,k4,res=0.0;
    cout<<"Enter the range : ";
    cin>>a>>b;
    cout<<"Enter the initial values : ";
    cin>>x>>y;
    cout<<"Enter the step size : ";
    cin>>h;
    cout<<"X\t\tY4rk"<<endl;
    cout<<x<<"\t\t"<<y<<endl;
    for(a;a<b;a+=h)
    {
        k1=f(x,y);
        k2=f(x+1.0/2.0*h,y+1.0/2.0*k1*h);
        k3=f(x+1.0/2.0*h,y+1.0/2.0*k2*h);
        k4=f(x+h,y+k3*h);
        res=y+(1.0/6.0)*(k1+2*k2+2*k3+k4)*h;
        cout<<x+h<<"\t\t"<<res<<endl;
        y=res;
        x=x+h;
    }
}

