#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    printf("Enter the number of unknowns :");
    scanf("%d",&n);
    float a[n+1][n+2], x[n+1], es, ea = 1000;
    printf("Enter the coefficients:\n\n");
    for(int i = 1; i <= n; i++)
    {
        x[i] = 0.0f;
        for(int j = 1; j <= n+1; j++)
        {
             scanf("%f",&a[i][j]);
        }
    }
for(int i = 1; i <= n; ++i)
    {
        if(a[i][i] == 0)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(a[i][j] != 0 && a[j][i] != 0)
                {
                    for(int k = 1; k <= n+1; ++k)
                    {
                        float t = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = t;
                    }
                }
            }
        }
        if(a[i][i] == 0)
        {
            printf("The solution of the equations is not possible.");
        }
    }
    printf("Input prespecified percent tolerance: ");
    scanf("%f",&es);
    int i = 1;
    while(ea > es)
    {
        printf("\n\nIteration %d :\n",i++);
        ea = 0;
        for(int i = 1; i <= n; ++i)
        {
            float sum = 0;
            for(int j = 1; j <= n; ++j)
            {
                if(i != j)
                    sum += a[i][j] * x[j];
            }
            float xold = x[i];
            x[i] = (a[i][n+1] - sum) / a[i][i];
            printf("\nx%d=%f\t",i,x[i]);
            if(x[i] != 0.0f)
            {
                float error = abs((x[i] - xold)/x[i])*100;
                printf("error = %f",error);
                if(error > ea)
                    ea = error;
            }
            else
            {
                printf("Error can't be calculated .");
            }
        }
    }
}


