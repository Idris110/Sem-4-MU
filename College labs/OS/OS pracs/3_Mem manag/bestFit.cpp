#include<bits/stdc++.h>

using namespace std;

int main(){
    vector <int> partition = {20,40,10,50,40};
    vector <pair <int,int>> process = {{10,-1},{40,-1},{20,-1},{30,-1}};
    // vector <int> allocated = {-1,-1,-1,-1};

    int pro=4,part=5;
    int nextInd=0;
    
    for(int i=0;i<process.size();i++){
        for(int j=0;j<partition.size();j++){
            if(process[i].second == -1 && process[i].first<=partition[j])
                process[i].second = j;
            else if(process[i].first <= partition[j] && partition[process[i].second] > partition[j])
                 process[i].second = j;
        }
        if(process[i].second != -1){
            partition[process[i].second] -= process[i].first;
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
