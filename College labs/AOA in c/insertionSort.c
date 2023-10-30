#include<stdio.h>

int* intSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j, temp = arr[i];
        
        for (j = i-1; j >= 0; j--)
        {
            if(temp<arr[j]) arr[j+1] = arr[j];
            else break;
        }
        arr[j+1]=temp;
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 3, 5, 1, 2};
    int n = 5;

    int *a =intSort(arr,n);

    for (int i = 0; i < n; i++) printf("%d ",a[i]);
    
    return 0;
}
