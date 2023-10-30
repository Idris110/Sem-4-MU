#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int left, int mid, int right){
    int temp[right-left+1];
    int i=left,j=mid+1,k=0;

    while(i<= mid && j<= right){
        if(arr[i]<arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j<=right){
        temp[k]= arr[j];
        j++;
        k++;
    }

    for(i=0;i<right-left+1;i++){
        arr[i+left] = temp[i];
    }
    
}

void mergesort(int arr[], int left, int right){
    if(left < right){
        int mid = (right + left)/2;
        // cout<<mid<<" ";
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }
}

int main(){
	//vector <int> arr{4,2,5,6,1,3,7};// 1,3,5,|2
    int n= 7;
	int arr[n] = {4,2,5,6,1,3,7};
    
    mergesort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
