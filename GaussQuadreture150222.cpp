 #include<bits/stdc++.h>
using namespace std;
double a,b;
double f(double X)
{
    return (exp(X)*sin(X))/(1+pow(X, 2));
}
int main()
{
    double val2, val3,f_13,f_35,f_0,f_n35,f_n13, range1, range2, seg=0, segp=0,seg1, seg2, seg3, seg4;
    cout<<"The function is : (e^x*sinx)/(1+x^2)"<<endl;
    cout<<"Enter the limits"<<endl;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    seg = (b - a)/2;
    segp=(b+a)/2;
    seg1 =(seg*0.577350269)+segp;
    seg2 =(seg*-0.577350269)+segp;
    f_0 = f((seg*0)+segp);
    f_13 = f(seg1);
    f_n13 = f(seg2);
    f_35 = f((seg*0.774596669)+segp);
    f_n35 = f((seg*-0.774596669)+segp);

    val2 = seg*(f_13 + f_n13);
    val3 = seg*(.5555556*f_n35+.8888889*f_0+.5555556*f_35);

    cout<<endl;
    cout<<"For two point the value is: "<<val2<<endl;
    cout<<"\nFor three point the value is: "<<val3<<endl;

}
