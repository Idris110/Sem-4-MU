#include <bits/stdc++.h>        
using namespace std;

int target;

void sos(vector <int> &arr, vector <int> &subset, int k){
    if(k == arr.size()){
        int sum=0;
        for(int i=0; i< subset.size();i++)
            sum += subset[i];

        if(sum == target){
            for(int i=0;i<subset.size();i++) 
                cout<<subset[i]<<" ";
            cout<<endl;
        }
            return ;
    }

    sos(arr, subset, k+1);

    subset.push_back(arr[k]);
    sos(arr, subset, k+1);

    subset.pop_back();
}

int main(void) {
    int n;
    cout << "Enter number of elements:" << endl;
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements:\n";
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << "Enter target sum:\n";
    cin >> target;
    vector<int> empty;
    // cout << ln;
    sos(a, empty, 0);
}

