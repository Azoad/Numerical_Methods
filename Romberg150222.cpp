#include<bits/stdc++.h>
using namespace std;
double a,b;
double f(double X)
{
    return (exp(X)*sin(X))/(1+pow(X, 2));
}
double trapezoidal(double n)
{
    double fa,fb,fav=0.0,segment,temp,res=0.0;
    segment = (b-a)/n;
    fa = f(a);
    fb = f(b);
    temp = a;
    for(int i=1;i<n;i++)
    {
        temp = temp+segment;
        fav = fav+f(temp);
    }
    res = (segment*(fa+2*fav+fb))/2;
    return res;
}
int main()
{
    int order;
    cout<<"The function is : (e^x*sinx)/(1+x^2)"<<endl;
    cout<<"Enter the limits"<<endl;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    cout<<"Enter the order = ";
    cin>>order;
    double h[10],h4[10],h6[10],h8[10];

    int j=1;
    for(int i=1; i<=order; i *= 2)
    {
        h[j] = trapezoidal(i);
        j++;
    }

    for(int i=4; i>1; i--)
    {
         h4[i-1] = ((4.0*h[i])/3.0) - (h[i-1]/3.0);
    }
    for(int i=3; i>1; i--)
    {
        h6[i-1] = ((16.0*h4[i])/15.0) - (h4[i-1]/15.0);
    }
    h8[1] = ((64.0*h6[2])/63.0) - (h6[1]/63.0);

    cout<<"\n\tO(h^2)\t\tO(h^4)\t\tO(h^6)\t\tO(h^8)\n\n";
    for(int i=1; i<=4; i++)
    {
        cout<<"\t"<<h[i]<<"\t\t";
        if(i<=3)
            cout<<h4[i]<<"\t\t";
        if(i<=2)
            cout<<h6[i]<<"\t\t";
        if(i==1)
            cout<<h8[i]<<"\t\t";
        cout<<"\n";
    }
}
