#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cout << "Enter track size:\n";
    int t;
    cin >> t;
    cout << "\nEnter size of request queue:\n";
    int n;
    cin >> n;
    vector<int> a(n);
    cout << "\nEnter request queue:\n";
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << "\nEnter starting position:\n";
    int starting;
    cin >> starting;
    cout << "\nChoose starting direction:\n1.Right\n2.Left\n";
    cout << "\nEnter choice:  ";
    int choice;
    cin >> choice;
    
    int total = 0;
    vector<int> ans;
    ans.push_back(starting);
    
    if(choice == 1) {
        for(int i=0; i<n; i++) {
            if(a[i] >= starting) {
                ans.push_back(a[i]);
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(a[i] <= starting) {
                ans.push_back(a[i]);
            }
        }
        total += (a[n-1] - starting + a[n-1] - a[0]);
    }
    
    if(choice == 2) {
        for(int i=n-1; i>=0; i--) {
            if(a[i] <= starting) {
                ans.push_back(a[i]);
            }
        }
        for(int i=0; i<n; i++) {
            if(a[i] >= starting) {
                ans.push_back(a[i]);
            }
        }
        total += (starting - a[0] + a[n-1] - a[0]);
    }
    
    cout << "\nHead movement is:\n";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " -> ";
    }
    cout << "Stop\n";
    cout << "\nTotal head movement = " << total;
}

/*
    7
    82 170 43 140 24 16 190
*/
