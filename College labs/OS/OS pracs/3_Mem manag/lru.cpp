#include<bits/stdc++.h>

using namespace std;

int main(){
    cout << "Enter the number of page frames in memory:\n";
    int p;
    cin >> p;

    vector<int> pages;
    cout << "Enter string length:\n";
    int n;
    cin >> n;
    vector<int> pgstr(n);
    cout << "Enter page string:\n";
    for(int i=0; i<n; i++) {
        cin >> pgstr[i];
    }
    cout << endl;
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<pages.size();j++){
            if(pgstr[i] == pages[j]) break;
        }
        if(j!=pages.size()){ //checks if already present
            pages.erase(pages.begin()+j);
            pages.push_back(pgstr[i]);
            cout<<"Page hit   -> ";
        }
        else{
            cout<<"Page fault -> ";
            if(pages.size() == p) 
            pages.erase(pages.begin());//checks if block is full
            
            pages.push_back(pgstr[i]);
        }

        for(int itr=0; itr<pages.size(); itr++) {
            cout << pages[itr] << ' ';
        }
        cout<<endl;
    }
}
