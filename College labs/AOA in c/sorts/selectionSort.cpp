#include<bits/stdc++.h>
using namespace std;

int main (){
    vector <int> arr{5,2,6,1,7,2,3,4};

    for(int i=0;i<arr.size();i++){
        int minInd = i;
        for(int j=i+1;j<arr.size();j++){
            minInd = (arr[j] < arr[minInd]) ? j : minInd;
        }
        
        int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}