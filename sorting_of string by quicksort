#include<bits/stdc++.h>
#include<string>
using namespace std;


int partition1 (string &arr, int low, int high)
{
    char pivot = arr[high];
      
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
       
            char t=arr[i];
            arr[i]= arr[j];
            arr[j]=t;
         
        }
    }
           char t=arr[high];
            arr[high]= arr[i+1];
            arr[i+1]=t;
        
          return (i + 1);

}


void quickSort(string &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition1(arr, low, high); 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
      
    }
}
int main()
{
    string str1;
    string str2;
    cout<<"enter 1st string "<<endl;
    cin>>str1;
    



    //sort(str.begin(), str.end());

    quickSort(str1,0,str1.length()-1);
   
   cout<<str1;
  


}
