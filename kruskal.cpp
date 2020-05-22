#include<iostream>
#include<algorithm>
using namespace std;
class edge{
    public :
    int source;
    int dest;
    int weight;
};
int findparent(int v ,int *parent) {
    if(parent[v]==v)
    {
        return v;
    }
    return findparent(parent[v],parent);
}
bool compare(edge e1 ,edge e2)
{
    return e1.weight < e2.weight ;
}
void kruskals(edge *input , int n , int E)
{
    //sort the input array - assanding order basedd on weight
    sort( input, input + E,compare);
    edge *output = new edge[n-1];
   int *parent = new int [n];
   for(int i=0;i<n;i++)
    parent[i]=i ;

    int count =0;
    int i = 0 ;
    while(count != n-1)
    {
        edge currentedge = input[i];
        //check if we can add the currentedge in mst or not
        int sourseparent = findparent(currentedge.source , parent);
        int destparent =findparent(currentedge.dest , parent);
       if(sourseparent != destparent)
       {
        output[count] = currentedge;
        count++;
        parent[sourseparent] = destparent;
       }
       i++;



   }
   for(int i=0;i<n-1;i++)
   {
       if(output[i].source < output[i].dest)
       {
      cout<<output[i].source<<" " <<output[i].dest<< " "<<
      output[i].weight << endl;
       }
       else
       {
           {
               cout<<output[i].dest<<" " <<output[i].source<< " "<<
      output[i].weight << endl;
           }
       }

   }


}
int main()
{
    int n,E;
   cout<<"enter no. of vertex and edges"<<endl;
    cin>>n>>E;
    edge *input = new edge[E];
    cout<<"enter all edges having source vertex and destination vertex and weight"<<endl;
    for(int i=0;i<E;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;

    }
    cout<<"\nminimum spanning tree is"<<endl;
     kruskals(input , n ,E);
     return 0;
}
