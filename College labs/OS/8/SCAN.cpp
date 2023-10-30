#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> request;
    cout<<"Enter the size of disk : ";
    int size;
    cin>>size;
    size--;
    cout<<"Enter number of request : ";
    int n;
    cin>>n;
    cout<<"Enter the requests :"<<endl;

    for(int i=0;i<n;i++) {
        int inp;
        cin>>inp;
        request.push_back(inp);
    }
    cout<<"Enter the position of head : ";
    int head;
    cin>>head;
    bool fromLeft=false;
    sort(request.begin(),request.end());
    int cutoffInd;

    for(cutoffInd=0; cutoffInd<n; cutoffInd++)
        if(request[cutoffInd]>head) break;
    
    cout<<"Movement of head : \n"<<head;
    if(fromLeft){
        for(int i=cutoffInd-1;i>=0;i--) cout<<" => "<<request[i];
        for(int i=cutoffInd; i<n; i++) cout<<" => "<<request[i];

        cout<<"\nTotal head movements : "<<request[n-1]+head<<endl;
    }
    else{
        for(int i=cutoffInd; i<n; i++) cout<<" => "<<request[i];
        cout<<" => "<<size;
        for(int i=cutoffInd-1;i>=0;i--) cout<<" => "<<request[i];

        cout<<"\nTotal head movements : "<<2*size-head-request[0]<<endl;    
    }
    return 0;
}