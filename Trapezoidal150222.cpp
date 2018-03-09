#include<bits/stdc++.h>
using namespace std;
double f(double X)
{
    return (exp(X)*sin(X))/(1+pow(X, 2));
}
int main()
{
    double a,b,n,fa,fb,fav=0.0,segment,temp,res;
    cout<<"The function is : (e^x*sinx)/(1+x^2)"<<endl;
    cout<<"Enter the limits"<<endl;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    cout<<"Enter the number of segment = ";
    cin>>n;
    segment = (b-a)/n;
    fa = f(a);
    fb = f(b);
    temp = a;
    for(int i=1; i<n; i++)
    {
        temp = temp+segment;
        fav = fav+f(temp);
    }
    res = (segment*(fa+2*fav+fb))/2;
    cout<<"The integration result is = "<<res;
}
