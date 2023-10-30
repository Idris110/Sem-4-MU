#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {5,2,1,4,3};
    int len = 5;
    selectionSort(arr,len);

    for(int i=0;i<len;i++) printf("%d ",arr[i]); 

    return 0;
}

void selectionSort(int arr[], int len) {
    for(int i=0;i<len-1;i++){
        int min = i;
        for(int j=i+1;j<len;j++){
            if(arr[min]>arr[j]) min = j;
        }
        
        int temp = arr[i];
        arr[i] = arr [min];
        arr[min] = temp;
    }
}