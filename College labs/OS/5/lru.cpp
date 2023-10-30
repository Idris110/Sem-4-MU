#include            <bits/stdc++.h>
using namespace std;

int main(void) {
    cout << "Enter page size:\n";
    int p;
    cin >> p;
    vector<int> pages;
    cout << "Enter string length:\n";
    int n;
    cin >> n;
    vector<int> a(n);
    cout << "Enter page string:\n";
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << endl;
    for(int i=0; i<n; i++) {
        if(pages.size() != p) {
            pages.push_back(a[i]);
        }        
        else {
            int index = 0;
            for(int pos=0; pos<p; pos++) {
                if(pages[pos] == a[i]) {
                    index = pos;
                }
            }
            pages.erase(pages.begin()+index);
            pages.push_back(a[i]);
        }
        for(int itr=0; itr<pages.size(); itr++) {
            cout << pages[itr] << ' ';
        }
        cout << endl;
    }
}