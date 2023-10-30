#include<bits/stdc++.h>
using namespace std;

int main(){
	int n = 3;
	int m = 50;
	int prof[n] = {60, 100, 120};
	int weight[n] = {10, 20, 30};
	
	vector <int> pwrat(n);
	
	for(int i=0;i<n;i++){
		pwrat[i] = (float)prof[i]/weight[i];
	}
	
	for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(pwrat[j]<pwrat[j+1]){
                float tem = pwrat[j];
                pwrat[j] = pwrat[j+1];
                pwrat[j+1] = tem;
                int temp = prof[j];
                prof[j] = prof[j+1];
                prof[j+1] = temp;
                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;
            }
        }
    }

    float totWt = 0, totProf=0;
    for(int i=0;i<n;i++){
        if(totWt + weight[i] <= m){
            totWt += weight[i];
            totProf += prof[i];
        }
        else{
            int rem = m - totWt;
            totProf += rem * pwrat[i];
            break;
        }
    }

    cout<<totProf<<endl;
}


