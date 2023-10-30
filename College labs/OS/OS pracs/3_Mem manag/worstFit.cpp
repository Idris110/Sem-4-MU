#include<bits/stdc++.h>

using namespace std;

int main(){
    vector <int> partition = {20,40,10,50,30};
    vector <pair <int,int>> process = {{10,-1},{40,-1},{20,-1},{30,-1}};
    // vector <int> allocated = {-1,-1,-1,-1};

    int maxInd;
    for(int i=0;i<process.size();i++){
        maxInd = 06;
        for(int j=1;j<partition.size();j++){
            if(process[i].first<=partition[j]){
                maxInd = (partition[maxInd] < partition[j]) ? j : maxInd;   
            }
        }
        if(maxInd != -1){
            partition[maxInd] -= process[i].first;
            process[i].second = maxInd;
        }
    }
    for(int i=0;i<process.size();i++){
        cout<<process[i].first<<"  "<<process[i].second<<endl;
    }
    cout<<endl<<"partition"<<endl;
    for(int i=0;i<partition.size();i++){
        cout<<partition[i]<<endl;
    }
    
}
