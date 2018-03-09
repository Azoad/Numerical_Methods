#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the order of polynomial: ";
    cin>>m;
    cout<<"Enter the value of n: ";
    cin>>n;
    double x[n],y[n];
    cout<<"Enter the values of x and y:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    double sumxi[m*2]= {0};
    for(int i=0; i<m*2; i++)
    {
        for(int j=0; j<n; j++)
        {
            sumxi[i]+=pow(x[j],(i+1));
        }
    }
    double sumx,sumy;
    sumx=sumy=0;
    for(int i=0; i<n; i++)
    {
        sumx+=x[i];
        sumy+=y[i];
    }
    double ym;
    ym=sumy/n;

    double eqn[m+1][m+2];
    eqn[0][0]=n;
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            if(i==0&&j==0)
            {
                continue;
            }
            else
            {
                eqn[i][j]=sumxi[i+j-1];
            }
        }
    }
    double sumxiy[m+1]= {0};
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n; j++)
        {
            sumxiy[i]+=pow(x[j],i)*y[j];
        }
    }
    for(int i=0; i<m+1; i++)
    {
        eqn[i][m+1]= sumxiy[i];
    }

    double a[m+1]= {0};
    double factor;

    for(int k=0; k<m; k++)
    {
        for(int i=k; i<m; i++)
        {
            factor= (eqn[i+1][k]/eqn[k][k]) ;
            for(int j=0; j<=m+1; j++)
            {
                eqn[i+1][j]=eqn[i+1][j]-factor*eqn[k][j];
            }
        }
    }
    double sum;
    for(int i=m; i>=0; i--)
    {
        sum=0;
        for(int j=i; j<=m; j++)
        {
            sum=sum+eqn[i][j]*a[j];
        }

        a[i]=(eqn[i][m+1]-sum)/eqn[i][i];
    }

    double sri[n]= {0};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            sri[i]-=a[j]*pow(x[i],j);
        }
        sri[i]=pow((y[i]+sri[i]),2);
    }
    double st,sr;
    st=sr=0;
    for(int i=0; i<n; i++)
    {
        st+=pow((y[i]-ym),2);
        sr+=sri[i];
    }
    double r,syx;
    syx=sqrt(sr/(n-(m+1)));
    r=sqrt((st-sr)/st);


    cout<<endl<<"Equation:"<<endl;
    cout<<"y = "<<a[0]<<" + "<<a[1]<<"x";
    for(int i=2; i<=m; i++)
    {
        cout<<" + ("<<a[i]<<")x"<<i;
    }
    cout<<endl<<endl<<"Standard error of the estimate: "<<syx<<endl;
    cout<<endl<<"Correlation coefficient: "<<r<<endl;
}

