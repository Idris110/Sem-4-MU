#include<bits/stdc++.h>
using namespace std;

int main(void) {
    cout << "Enter page size:\n";
    int pageSize;
    cin >> pageSize;
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
        if(pages.size() == 0) {
            pages.push_back(a[i]);
        }
        else {
            int index = 0;
            for(int j=0; j<pages.size(); j++) {
                if(pages[j] == a[i]) {
                    index = j;
                    break;
                }
            }
            if(index != 0) {
                pages.erase(pages.begin()+index);
            }
            else {
                if(pages.size() == pageSize) {
                    pages.erase(pages.begin());
                }
            }
            pages.push_back(a[i]);
        }
        for(int j=0; j<pages.size(); j++) {
            cout << pages[j] << ' ';
        }
        cout << endl;
    }
}