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
    int point[pairs];
    double f[pairs];
    cout<<"\nEnter the data points and values: "<<endl;
    for(int i=0;i<pairs;i++){
        cin>>point[i];
        cin>>f[i];
    }
    int value;
    cout<<"\nEnter the evaluation value :";
    cin>>value;
    double sum=0;
    double product;
    for(int i=0;i<=order;i++){
        product=f[i];
        for(int j=0;j<=order;j++){
            if(i!=j){
                product=(product*(value-point[j]))/(point[i]-point[j]);
            }
        }
        sum+=product;
    }
    cout<<endl<<"Evaluated value: "<<sum<<endl;
}
