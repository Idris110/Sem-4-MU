#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<vector<int>> allocation(5, vector<int>(3)), 
                        maxNeed(5, vector<int>(3)), 
                        remNeed(5, vector<int>(3));
    cout << "Enter number of resources of type A, B, C:\n";
    int a, b, c;
    cin >> a >> b >> c;
    cout << "\nEnter allocation matrix:\n";
    cout << "A B C\n";
    vector<int> totalAllocated(3);
    for(int i=0; i<5; i++) {
        for(int j=0; j<3; j++) {
            cin >> allocation[i][j];
            totalAllocated[j] += (allocation[i][j]);
        }
    }
    cout << "\nEnter max need matrix:\n";
    cout << "A B C\n";
    for(int i=0; i<5; i++) {
        for(int j=0; j<3; j++) {
            cin >> maxNeed[i][j];
        }
    }
    for(int i=0; i<5; i++) {
        for(int j=0; j<3; j++) {
            remNeed[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }
    vector<int> available(3);
    available[0] = a - totalAllocated[0];
    available[1] = b - totalAllocated[1];
    available[2] = c - totalAllocated[2];
    for(int it=0; it<5; it++) {
        bool deadlock = true;
        bool canExecute = true;
        for(int i=0; i<5; i++) {
            bool canExecute = true;
            for(int j=0; j<3; j++) {
                if(remNeed[i][j] > available[j]) {
                    canExecute = false;
                }
            }
            if(canExecute) {
                deadlock = false;
                for(int j=0; j<3; j++) {
                    available[j] += allocation[i][j];
                }
            }
        }
        if(deadlock) {
            cout << "Deadlock occurs!";
            return 0;
        }
    }
    cout << "\nRemaining need matrix:\n";
    for(int i=0; i<5; i++) {
        for(int j=0; j<3; j++) {
            cout << remNeed[i][j] << ' ';
        }
        cout << endl;
    }    
}


/*
    
total 
10 5 7 

7 5 3
3 2 2
9 0 2
4 2 2
5 3 3


0 1 0
2 0 0
3 0 2
2 1 1
0 0 2


*/