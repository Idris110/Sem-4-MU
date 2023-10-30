#include<bits/stdc++.h>
using namespace std;

int main(){
	vector <int> arr{4,2,5,6,1,3,7};// 1,3,5,|2
	for(int i=1;i<arr.size();i++){
		int temp = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1] = arr[j];
            j--;
		}
        j++;
        arr[j] = temp;
	}

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
