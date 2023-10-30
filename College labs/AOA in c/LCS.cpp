#include<bits/stdc++.h>

using namespace std;

int main(){
    string str1 = "bacdb";//m,i
    string str2 = "bdcb";//n,j

    int m=str1.size(),n=str2.size();
    int mat[m+1][n+1];

    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0) 
            mat[i][j]=0;

            else if(str1[i-1]==str2[j-1]){
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else{
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\nLCS : ";
    int i=m,j=n;
    while(i!=0 && j!=0){
        if(mat[i][j]==mat[i-1][j]){
            i--;
        }
        else if(mat[i][j]==mat[i][j-1]){
            j--;
        }
        else if(mat[i][j]==mat[i-1][j-1]+1){
            cout<<str2[j-1];
            i--;
            j--;
        }
    }

}