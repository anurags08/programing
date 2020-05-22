
#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int src, dest, weight;
};
struct Graph {

	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void printArr(int dist[], int n)
{
	cout<<"Vertex Distance from Source\n";
    cout<<"vertex\t\tdistance\n";
	for (int i = 1; i <= n; ++i)
		cout<<i<<"\t\t"<<dist[i]<<endl;
}

void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])


				dist[v] = dist[u] + weight;

		}
	}


	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			cout<<"Graph contains negative weight cycle";
			return;
		}
	}

	printArr(dist, V);

	return;
}


int main()
{
    int v,e,s,d,w;
    cout<<"enter vertex and edges\n";
    cin>>v>>e;
    struct Graph* graph = createGraph(v, e);
    cout<<"enter source node and destination node and weight\n";
    for(int i=0;i<e;i++)
    {
        cin>>s;
        graph->edge[i].src=s;

        cin>>d;
        graph->edge[i].dest=d;
        cin>>w;
        graph->edge[i].weight=w;
    }
cout<<"\nenter vertex from which you want to dist\n";
cin>>e;


	BellmanFord(graph, e);

	return 0;
}
