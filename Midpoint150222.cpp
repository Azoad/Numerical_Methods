#include<bits/stdc++.h>
using namespace std;
double f(double X,double Y)
{
    return (1+2*X)*pow(Y,.5);
}
/*double equ(double X)
{
    return (4.0/1.3)*(exp(0.8*X)-exp(-.05*X))+2*exp(-.05*X);
}*/
main()
{
    double a,b,x,y,h,res=0.0,y0,y1,yavg;
    cout<<"Enter the range : ";
    cin>>a>>b;
    cout<<"Enter the initial values : ";
    cin>>x>>y;
    cout<<"Enter the step size : ";
    cin>>h;
    cout<<"X\t\tYmidpoint"<<endl;
    for(a;a<=b;a+=h)
    {
        y0=y+(h/2.0)*f(x,y);
        y1=f(x+(h/2.0),y0);
        res = y+y1*h;
        cout<<x<<"\t\t"<<y<<endl;
        y=res;
        x=x+h;
    }
}

