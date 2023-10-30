#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {6,3,2,4,1,5,10,9,7,8};
    int n = 10;
    mergeSort(arr,n,0,n-1);

    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}

void mergeSort(int arr[], int n, int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(arr,n,lb,mid);
        mergeSort(arr,n,mid+1,ub);
        merge(arr,n,lb,mid,ub);
    }
}

void merge(int arr[], int n, int lb, int mid, int ub){
    int i=lb , j=mid+1, k=0;
    int tempArr[ub-lb+1];

    while(i<=mid && j<=ub){
        if(arr[i]<arr[j]){
            tempArr[k] = arr[i];
            i++;
        }else{
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        tempArr[k]=arr[i];
        i++;
        k++;
    }
    while(j<=ub){
        tempArr[k]=arr[j];
        j++;
        k++;
    }

    for(int i=lb;i<=ub;i++)
        arr[i]=tempArr[i-lb];
}