#include <bits/stdc++.h>
using namespace std;

int primeFactors(long long int n,long long int k)  
{  
    long long int l=0;
    
    while (n % 2 == 0)  
    {  
          l=l+1;
        n = n/2;  
    }  
  
    
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
         
        while (n % i == 0)  
        {  
            l=l+1;  
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
        l=l+1 ;
        
        if(l>=k)
        return 1;
        else
        return 0;
}  
  

int main()
{
 long long  int t,x,k,j, i;
 cin>>t;
 for(i=0;i<t;i++)
 {
  cin>>x>>k;
  
  
      if(primeFactors(x,k))
      cout<<"1"<<endl;
      else
      cout<<"0"<<endl;
  }
  return 0;
}
