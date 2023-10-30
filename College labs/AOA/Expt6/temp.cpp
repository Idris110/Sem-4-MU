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
    for (int i = 0; i < n; ++i) cout << dist[i] << " ";
    cout << endl;
}

void printArr(vector<int>& arr, int n)
{
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

//printing path functions
void printPath(vector<int> const &parent, int vertex, int source)
{
    if (vertex < 0) {
        return;
    }

    printPath(parent, parent[vertex], source);
    if (vertex != source) {
    cout << " ---> ";
    }
    cout << vertex;
}

void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    vector<int> parent (V, -1);
    for (int i = 0; i < V; i++)
        dist[i] = 9999;
    dist[src] = 0;
    cout << "Shortest path estimate after initialization" << endl;
    printArr(dist,V); cout << endl;
    cout << "Predecessor after initialization" << endl;
    printArr(parent,V); cout << endl;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != 9999 && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != 9999
            && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle";
            return; 
        }
    }
    cout << "Shortest path estimate" << endl;
    printArr(dist, V); cout << endl;
    
    cout << "Predecessor" << endl;
    printArr(parent,V); cout << endl;
    cout << "Single source shortest path exists" << endl << endl;
    for (int i = 0; i < V; i++)
    {
        if (i != src && dist[i] < 9999)
        {
            cout <<"Path from " << src << " to " << i << " is ";
            printPath(parent, i, src);
            cout << endl;
        }
    }
    return;
}

int main()
{
    cout << "Enter number of vertices and edges of the graphs\n";
    int V,E; cin >> V >> E;
    struct Graph* graph = createGraph(V, E);
    
    cout << "Enter source vertex, destination vertex and the weight between them\n";
    for(int i=0;i<E;i++) {
        cin >> graph->edge[i].src;
        cin >> graph->edge[i].dest;
        cin >> graph->edge[i].weight;
    }
    printf("Edge table\n");
    for(int i=0;i<E;i++) {
        cout << graph->edge[i].src << " ---> " << graph->edge[i].dest << " : " << graph->edge[i].weight << endl;
    }
    cout << "Enter source vertex in graph" << endl;
    int src; cin >> src;
    cout << endl;
    BellmanFord(graph, src);
    return 0;
}
