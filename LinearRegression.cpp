#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Number of elements : ";
    cin>>n;
    double x[n],y[n],sumx=0,sumy=0,sumxy=0,sumx2=0,a1,a0,sr=0,st=0,sydx,r;
    cout<<"Enter the values of x and y"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        sumx=sumx+x[i];
        sumy=sumy+y[i];
        sumxy=sumxy+x[i]*y[i];
        sumx2=sumx2+x[i]*x[i];
    }
    cout<<endl;
    a1=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    a0=(sumy/n)-a1*(sumx/n);
    double meanY=sumy/n;
    for(int i=0; i<n; i++)
    {
        sr = sr + pow((y[i]-a0-a1*x[i]),2);
        st = st + pow((y[i]-meanY),2);
    }
    sydx = pow((sr/(n-2)),0.5);
    r = pow(((st-sr)/st),0.5);
    cout<<"The equation is : y="<<a0<<"+"<<a1<<"x"<<endl;
    cout<<"Standard error of the estimate : "<<setprecision(4)<<sydx<<endl;
    cout<<"Corelation coefficient : "<<setprecision(3)<<r<<endl;
}
