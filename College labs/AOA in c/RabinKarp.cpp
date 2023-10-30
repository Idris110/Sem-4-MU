#include<bits/stdc++.h>
// #define sp          ' '
// #define ln          '\n'             
// #define fs          first
// #define sc          second
// const int px[8]  =  {0,0,-1,1,-1,-1,1,1};
// const int py[8]  =  {-1,1,0,0,-1,1,-1,1};
using namespace std;

int main(void) {
    string a, b;
    cout << "Enter string:\n";
    cin >> a;
    cout << "Enter pattern:\n";
    cin >> b;
    int n = a.size(), m = b.size();

    int aCode = 0, bCode = 0, h=5;
    for(int i=0;i<m;i++){
        aCode += (a[i] - 'a' + 1)*pow(h, m-i-1);
        bCode += (b[i] - 'a' + 1)*pow(h, m-i-1);
    }

    cout<<aCode<<" | "<<bCode;

    for(int i=0 ; i<n-m ; i++){
        if(aCode == bCode) cout << "found at index : "<<i+1<<endl;
        
        aCode -= (a[i] - 'a' + 1)*pow(h, m-1);
        aCode *= h;
        aCode += (a[i+m] - 'a' + 1);
    }

}









    // for(int i=0; i<m; i++) {
    //     bCode += (b[i] - 'a' + 1) * pow(10, m-i-1);
    //     aCode += (a[i] - 'a' + 1) * pow(10, m-i-1); 
    // }
    // cout<<aCode<<" - "<<bCode;

    // for(int i=0; i<=n-m; i++) {
    //     if(aCode == bCode) {
    //         cout << "\nFound at position " << i+1;
    //         break;
    //     }
    //     aCode -= (a[i] - 'a' + 1) * pow(10, m-1);
    //     aCode *= 10;
    //     aCode += (a[i+m] - 'a' + 1);
    // }    