#include<bits/stdc++.h>
using namespace std;
double co_efficient[10];
int position;
double f(double X)
{
    return cos(X)-X*exp(X);
}
int main()
{
    cout<<"The equation is: cos(X)-X*exp(X)"<<endl;
    double Xl,Xu,Xr,xl,xu,Ea,p=0.0;
    cout<<"Value of Xl = ";
    cin>>Xl;
    cout<<"Value of Xu = ";
    cin>>Xu;
    cout<<"Percentage of Error = ";
    cin>>Ea;
    double fl,fu,fr;
    for(int i=1;; i++)
    {
        fl = f(Xl);
        fu = f(Xu);
        xu=Xu,xl=Xl;
        Xr=xu-((xl-xu)/(fl-fu))*fu;
        Xl=Xu;
        Xu=Xr;
        cout<<i<<"\tXl = "<<xl<<"\t\tXu = "<<xu<<"\t\tXr = "<<Xr<<"\t\tEa = "<< abs((Xr-p)/Xr)*100.0<<endl;
        if((abs((Xr-p)/Xr)*100.0)<=Ea)
        {
            cout<<"\nApproximate Root: "<<Xr;
            break;
        }
        p=Xr;
    }
}
