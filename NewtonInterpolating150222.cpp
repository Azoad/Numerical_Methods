#include<bits/stdc++.h>
using namespace std;
int main()
{
    int order;
    cout<<"Enter the order: ";
    cin>>order;
    int pairs;
    cout<<"Enter the no of pairs: ";
    cin>>pairs;
    int iter=0;
    for(int i=order; i>0; i--)
    {
        iter+=i;
    }
    int point[order+1];
    double f[iter+order+1];
    cout<<"\nEnter the data points and values: "<<endl;
    for(int i=0; i<pairs; i++)
    {
        cin>>point[i];
        cin>>f[i];
    }
    int value;
    cout<<"\nEnter the evaluation value: ";
    cin>>value;
    int inc = 0;
    int temp = order;
    int temp2 = order;
    int temp3 = order;
    int l = 1;
    for (int i = 0,j=0,k=0; i < iter; i++,j++,k++)
    {
        if (i == order)
        {
            inc = --temp;
            order += inc;
            j++;
            l += 1;
            k = 0;
        }
        f[i + temp3+1] = (f[j + 1] - f[j]) / (point[k + l] - point[k]);
    }
    double b[temp3+1];
    int temp4 = 0;
    int temp5 = temp3;
    for(int i = 0; i <= temp5; i++)
    {
        b[i] = f[temp4];
        temp4 += temp3 + 1;
        temp3--;
    }
    double sum = b[0];

    for(int i = 1; i <= temp5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            b[i] *= (value - point[j - 1]);
        }
        sum += b[i];
    }
    cout<<"\nEstimated value: f("<<value<<") = "<<sum<<endl;
}
