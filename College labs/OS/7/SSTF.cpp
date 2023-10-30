#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,bool>> request;
    cout<<"Enter number of request : ";
    int n,inp;
    cin>>n;
    cout<<"Enter the requests :"<<endl;

    for(int i=0;i<n;i++) {
        cin>>inp;
        request.push_back({inp,false});
    }

    cout<<"Enter the position of head : ";
    int head;
    cin>>head;
    int totalMov=0;
    cout<<"Movement of head : \n"<<head;

    for(int j=0;j<n;j++){
        int minDiff=INT_MAX, indx;
        
        for(int i=0;i<n;i++){
            if(!request[i].second && (abs(head-request[i].first)<minDiff)){
                minDiff=abs(head-request[i].first);
                indx=i;
            }
        }
        cout<<" => "<<request[indx].first;
        head=request[indx].first;
        request[indx].second=true;
        totalMov += minDiff ;
    }
    cout<<"\nTotal head movements : "<<totalMov<<endl;
    return 0;
}