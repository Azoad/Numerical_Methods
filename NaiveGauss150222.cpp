#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n;
    float a[10][10],c,x[10],sum=0.0;
    printf("Enter the number of unknowns :");
    scanf("%d",&n);
    printf("Enter the coefficients:\n\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n+1);j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i>j)
            {
                c=a[i][j]/a[j][j];
                for(k=1;k<=(n+1);k++)
                {
                    a[i][k]=a[i][k]-c*a[j][k];
                }
            }
        }
    }
    x[n]=a[n][n+1]/a[n][n];
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+a[i][j]*x[j];
        }
        x[i]=(a[i][n+1]-sum)/a[i][i];
    }
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]);
    }
}
