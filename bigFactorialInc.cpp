#include<bits/stdc++.h>
using namespace std;
void multi(int* x,int &m , int i)
{
    int carry=0;
    for(int j=0;j<m;j++)
    {
        int p=x[j]*i +carry;
        x[j]=p%10;
        carry=p/10;
    }
    while(carry>0)
    {
        x[m]=carry%10;
        carry=carry/10;
        m++;
    }
}
void factorial(int* x , int n)
{
    for(int i=0;i<1000;i++)
        x[i]=0;
    x[0]=1;
    int m=1;
    for(int i=2;i<=n;i++)
    {
        multi(x,m,i);

    }
    for( int i=m-1;i>=0;i--)
        cout<<x[i];
}
int main()
{
    int *x=new int[1000];
    int n;
    cout<<"enter no. for finding the factorial   ";
    cin>>n;
    factorial(x,n);

}
