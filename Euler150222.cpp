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
    double a,b,x,y,h,res=0.0;
    cout<<"Enter the range : ";
    cin>>a>>b;
    cout<<"Enter the initial values : ";
    cin>>x>>y;
    cout<<"Enter the step size : ";
    cin>>h;
    cout<<"X\t\tYeuler"<<endl;
    cout<<x<<"\t\t"<<y<<endl;
    for(a;a<b;a+=h)
    {
        res=y+h*f(x,y);
        cout<<x+h<<"\t\t"<<res<<endl;
        y=res;
        x=x+h;
    }
}
