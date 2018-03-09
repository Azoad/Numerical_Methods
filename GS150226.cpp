#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    printf("\nEnter the order of matrix A: ");
    cin >> n;

    float a[n+1][n+2], x[n+1], es, ea = 1000;

    printf("\nEnter the elements of augmented matrix row-wise:\n");

    for(int i = 1; i <= n; i++)
    {
        x[i] = 0.0f;
        for(int j = 1; j <= n+1; j++)
        {
            cin >> a[i][j];
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
            cout << "The solution of the equations is not possible." << endl;
            return 0;
        }
    }

    cout << "Input prespecified percent tolerance: " << endl;
    cin >> es;

    int i = 1;

    while(ea > es)
    {
        cout << endl << "Iteration " << i++ << " :" << endl;
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

            cout << "x" << i << " = " << x[i]  << "\t";

            if(x[i] != 0.0f)
            {
                float error = abs((x[i] - xold)/x[i])*100;
                cout << "%Error" << " = " << error  << " ." << endl;

                if(error > ea)
                    ea = error;
            }
            else
            {
                cout << "Error can't be calculated ." << endl;
            }
        }
    }

    return 0;
}
