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
    double Xu,Xl,Xr,Ea,xu,xl,p=0.0;
    cout<<"Value of Xl = ";
    cin>>Xl;
    cout<<"Value of Xu = ";
    cin>>Xu;
    cout<<"Percentage of Error: ";
    cin>>Ea;
    double fl,fu,fr;
    fl = f(Xl);
    fu = f(Xu);
    if(fl*fu>0)
        cout<<"There is no root";
    else
    {
        for(int i=1;;i++)
        {
            xu=Xu,xl=Xl;
            Xr = xu-((fu*(xl-xu))/(fl-fu));
            fr = f(Xr);
            if((fu*fr)<0)
                Xl = Xr;
            else
            {
                Xu = Xr;
                fu = fr;
            }
            cout<<i<<"\tXl = "<<xl<<"\t\tXu = "<<xu<<"\t\tXr = "<<Xr<<"\t\tEa = "<< abs((Xr-p)/Xr)*100.0<<endl;
            if((abs((Xr-p)/Xr)*100.0)<=Ea)
            {
                cout<<"\nApproximate Root: "<<Xr;
                break;
            }
            p=Xr;
        }
    }
}
