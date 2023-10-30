#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src, dest, weight;
};


void BellmanFord(int v, int e, vector <Edge> edge){
    int dist[v],pred[v];
    for(int i=0;i<v;i++){
         dist[i]=INT_MAX;
         pred[i]=-1;
    }
    dist[0] = 0;

    for(int j=0;j<v-1;j++){
        for(int i=0;i<e;i++){
            int s = edge[i].src;
            int d = edge[i].dest;
            
            if(dist[edge[i].src] != INT_MAX && (dist[s] + edge[i].weight < dist[d])){
                dist[d] = dist[s]+edge[i].weight;
                pred[d] = s;
            }
        }
    }

    for(int i=0;i<e;i++){
        if(dist[edge[i].src] + edge[i].weight < dist[edge[i].dest]){
            cout<<"Negative cycle !";
            break;
        }
    }

    for(int i=0;i<v;i++){
        cout<<pred[i]<<" -> "<<i<<"\twt :"<<dist[i]<<endl;
    }


}

int main(){
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    
    vector <Edge> edge(E);
 
    // add edge 0-1 (or A-B in above figure)
    edge[0].src = 0;
    edge[0].dest = 1;
    edge[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    edge[1].src = 0;
    edge[1].dest = 2;
    edge[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    edge[2].src = 1;
    edge[2].dest = 2;
    edge[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    edge[3].src = 1;
    edge[3].dest = 3;
    edge[3].weight = 2;
 
    // add edge 1-4 (or B-E in above figure)
    edge[4].src = 1;
    edge[4].dest = 4;
    edge[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    edge[5].src = 3;
    edge[5].dest = 2;
    edge[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    edge[6].src = 3;
    edge[6].dest = 1;
    edge[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    edge[7].src = 4;
    edge[7].dest = 3;
    edge[7].weight = -3;
 
    BellmanFord(V,E,edge);
 
    return 0;
}