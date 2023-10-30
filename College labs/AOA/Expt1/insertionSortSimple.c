#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {5,2,1,4,3};
    int len = 5;
    IntsertnSort(arr,len);

    for(int i=0;i<len;i++) printf("%d ",arr[i]); 

    return 0;
}

void IntsertnSort(int arr[], int len) {
    for(int i=1;i<len;i++){
        int temp = arr[i];
        // int j;
        // for(j=i-1;j>=0;j--){
        //     if(arr[j]>temp){
        //         arr[j+1] = arr[j];
        //     }
        //     else break;
        // }
        // arr[j+1]=temp;
        int j = i;
        while(j>0 && temp<arr[j-1]){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j]= temp;
    }
}