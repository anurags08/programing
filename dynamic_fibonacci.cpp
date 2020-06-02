
// code for dynamic programing for fibonacii series and nth fibanacci no. 
 
#include<iostream>
using namespace std;
int lookup[100000];
int fib(int n)
{
    if(lookup[n]==0)
    {
        if(n<=1)
            lookup[n]=n;
        else
            lookup[n]=fib(n-1)+fib(n-2);

    }
    return lookup[n];
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<100000;i++)
        lookup[i]=0;
    fib(n);
    for(i=0;i<n;i++)
    {
        cout<<lookup[i]<<" ";
    }

}
