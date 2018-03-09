#include<bits/stdc++.h>
using namespace std;
double co_efficient[10];
int position;
double f(double X)
{
    return cos(X)-X*exp(X);
}
double df(double X)
{
    return (-X-1)*exp(X)-sin(X);
}
int main()
{
    double X0,x0,fx,dfx,Xr,p=0.0,Ea;
    cout<<"The equation is: cos(X)-X*exp(X)"<<endl;
    cout<<"Value of X0 = ";
    cin>>X0;
    cout<<"Percentage of Error = ";
    cin>>Ea;
    for(int i=1;; i++)
    {
        fx = f(X0);
        dfx = df(X0);
        x0=X0;
        Xr = X0-(fx/dfx);
        X0 = Xr;
        cout<<i<<"\tX0 = "<<x0<<"\t\tXr = "<<Xr<<"\t\tEa = "<< abs((Xr-p)/Xr)*100.0<<endl;
        if((abs((Xr-p)/Xr)*100.0)<=Ea)
        {
            cout<<"\nApproximate Root: "<<Xr;
            break;
        }
        p=Xr;
    }
}
