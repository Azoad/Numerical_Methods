#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Number of elements : ";
    cin>>n;
    double a[3][4],b[3][4],x[n],y[n],xi=0.0,yi=0.0,x2=0.0,x3=0.0,x4=0.0,meanX,meanY,xiyi=0.0,x2y=0.0,a0,a1,a2,m,sr=0,p,sydx,s1,r1=0,r;
    cout<<"Enter the values of x and y "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        xi=xi+x[i];
        yi=yi+y[i];
        x2=x2+(x[i]*x[i]);
        x3=x3+(x[i]*x[i]*x[i]);
        x4=x4+(x[i]*x[i]*x[i]*x[i]);
        xiyi=xiyi+(x[i]*y[i]);
        x2y=x2y+(x[i]*x[i]*y[i]);
    }
    cout<<endl;
    meanX=xi/n;
    meanY=yi/n;
    a[0][0]=n,a[0][1]=xi,a[0][2]=x2,a[0][3]=yi;
    a[1][0]=xi,a[1][1]=x2,a[1][2]=x3,a[1][3]=xiyi;
    a[2][0]=x2,a[2][1]=x3,a[2][2]=x4,a[2][3]=x2y;
    m=a[1][0]/a[0][0];
    a[1][0]=(a[1][0]-(a[0][0]*m));
    a[1][1]=(a[1][1]-(a[0][1]*m));
    a[1][2]=(a[1][2]-(a[0][2]*m));
    a[1][3]=(a[1][3]-(a[0][3]*m));
    m=a[2][0]/a[0][0];
    a[2][0]=(a[2][0]-(a[0][0]*m));
    a[2][1]=(a[2][1]-(a[0][1]*m));
    a[2][2]=(a[2][2]-(a[0][2]*m));
    a[2][3]=(a[2][3]-(a[0][3]*m));
    m=a[2][1]/a[1][1];
    a[2][1]=(a[2][1]-(a[1][1]*m));
    a[2][2]=(a[2][2]-(a[1][2]*m));
    a[2][3]=(a[2][3]-(a[1][3]*m));
    a2=(a[2][3]/a[2][2]);
    a1=((a[1][3]-(a[1][2]*a2))/a[1][1]);
    a0=((a[0][3]-(a[0][2]*a2)-(a[0][1]*a1))/a[0][0]);

    cout<<"The equation is : y = "<<a0<<" + "<<a1<<"x ";
    if(a2<0)
        cout<<"- "<<abs(a2)<<"x^2"<<endl;
    else
        cout<<"+ "<<abs(a2)<<"x^2"<<endl;
    for(int i=0;i<n;i++)
    {
        sr=sr+(y[i]-a0-a1*x[i]-a2*x[i]*x[i])*(y[i]-a0-a1*x[i]-a2*x[i]*x[i]);
    }
    sydx=sqrt(sr/(n-3));
    cout<<"Standard error of the estimate : "<<sydx<<endl;
    for(int i=0;i<n;i++)
    {
        r1=r1+((y[i]-meanY)*(y[i]-meanY));
    }
    r=sqrt((r1-sr)/r1);
    cout<<"Corelation coefficient : "<<r<<endl;
}
