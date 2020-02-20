#include<bits/stdc++.h>
#include<string>
using namespace std;


int partition1 (string &arr, int low, int high)
{
    char pivot = arr[high];
       //cout<<pivot;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
         //   cout<<arr[i]<<" "<<arr[j]<<"-";
            char t=arr[i];
            arr[i]= arr[j];
            arr[j]=t;
          //  cout<<arr[i]<<" "<<arr[j]<<"|";
        }
    }
           char t=arr[high];
            arr[high]= arr[i+1];
            arr[i+1]=t;
           // cout<<arr<<" "<<endl;
          return (i + 1);

}


void quickSort(string &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition1(arr, low, high); // cout<<" low "<<low<<" high- "<<high" "<<arr<<endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
       // cout<<arr<<" ";
    }
}
int main()
{
    string str1;
    string str2;
    cout<<"enter 1st string "<<endl;
    cin>>str1;
    cout<<"enter 2nd string"<<endl;
    cin>>str2;



    //sort(str.begin(), str.end());

    quickSort(str1,0,str1.length()-1);
    quickSort(str2,0,str2.length()-1);
   cout<<str1<<" "<<str2;
   if(str1==str2)
        cout<<"\nYES";
    else
        cout<<"\nNO";


}
