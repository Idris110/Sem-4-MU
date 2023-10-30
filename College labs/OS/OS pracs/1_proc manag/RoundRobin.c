#include<stdio.h>

typedef struct proc{
    int id,burstRemain,tt,burst;
}proc;

int serviced(proc *arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i].burstRemain>0) return 1;
    }
    return 0;
}

int main(){
    int n,quantum;
    n=4;quantum = 20;
    proc arr[n];
    for(int i=0;i<n;i++){
        arr[i].id=i+1;
        scanf("%d",&arr[i].burst);
        arr[i].burstRemain = arr[i].burst;
    }
    printf("Id\trem bur\ttt\n");
    int turnaround = 0;

    while(serviced(arr,n)){
        for(int i=0;i<n;i++){
            if(arr[i].burstRemain == 0) continue;
            if(arr[i].burstRemain >= quantum){
                arr[i].burstRemain -= quantum;
                turnaround += quantum;

                printf("%d\t%d\t%d\n",arr[i].id,arr[i].burstRemain,turnaround);
                if(arr[i].burstRemain == quantum) arr[i].tt=turnaround;
            }
            else{
                turnaround += arr[i].burstRemain;
                arr[i].burstRemain = 0;

                arr[i].tt = turnaround;
            }
                printf("%d\t%d\t%d\n",arr[i].id,arr[i].burstRemain,turnaround);
        }
    }

    printf("\nId\tWt\tTt");
    int totWait=0,totTt=0;
    for(int i=0;i<n;i++){
        int wait = arr[i].tt-arr[i].burst;
        totWait += wait;
        totTt += arr[i].tt;

        printf("\n%d\t%d\t%d",arr[i].id,arr[i].tt-arr[i].burst,arr[i].tt);
    }
    printf("\nAvg tt = %f \nAvg wt = %f\n",(float)totTt/n,(float)totWait/n);
}