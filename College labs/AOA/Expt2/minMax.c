struct minMax {
    int greater, smaller;
};

int main(int argc, char const *argv[])
{
    int arr[] = {6,3,2,4,1,5,10,9,7,8};
    int n = 10;
    
    int *minMax;
    minMax = (int*)malloc(2 * sizeof(int));

    minMax = MinMax(arr,n,0,n-1);

    for(int i=0;i<2;i++)
    printf("%d ",arr[i]);  

    return 0;
}

int *MinMax(int arr[], int n, int low, int high){
    int *minMax;
    minMax = (int*)malloc(2 * sizeof(int));
    if(low==high){
        minMax[0]=minMax[1]=arr[low];
    }
    else if(high-low == 1){
        if(arr[low]>arr[high]){
            minMax[0]=arr[high];
            minMax[1]=arr[low];
        }
        else{
            minMax[1]=arr[high];
            minMax[0]=arr[low];
        }
    }
    else{
        int mid= (low+high)/2;

    }
}