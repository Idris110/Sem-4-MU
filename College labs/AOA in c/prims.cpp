#include<bits/stdc++.h>

using namespace std;

int main(){

    int v=5;            //0, 1, 2, 3, 4
    int graph[v][v]=  { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    
    int dist[v],pred[v];
    bool visited[v];

    for(int i=0;i<v;i++){
        visited[i]=false;
        dist[i]=INT_MAX;
    }
    pred[0]=-1;
    dist[0]=0;

    for(int i=0;i<v-1;i++){
        int minDist= INT_MAX, minInd=0;
        for(int j=0;j<v;j++){
            // cout<<visited[j]<<" "<<dist[j]<<", ";
            if(visited[j]==false && minDist > dist[j]){
                minDist = dist[j];
                minInd = j;
            }
        }
        // cout<<"=="<<minInd<<" "<<endl;
        visited[minInd]=true;

        for(int j=0;j<v;j++){
            if(graph[minInd][j] && visited[j]==false && graph[minInd][j] < dist[j]){
                dist[j] = graph[minInd][j];
                pred[j] = minInd;
            }
        }
    }

    for(int i=1;i<v;i++){
        cout<<i<<" - "<<pred[i]<<" => "<<graph[i][pred[i]]<<endl;
    }
    
    cout<<"\nLCS : ";


}