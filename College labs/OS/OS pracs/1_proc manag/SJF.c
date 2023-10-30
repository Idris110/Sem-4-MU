#include<stdio.h>

typedef struct proc{
    int id,burst;
}proc;

int main(){
    int n;
    n=4;
    proc arr[n];
    for(int i=0;i<n;i++){
        arr[i].id=i+1;
        scanf("%d",&arr[i].burst);
    }

    for(int i=0;i<n;i++){ //---------------swapping proc acc to priority
        for(int j=0;j<n-i-1;j++){
            if(arr[j].burst>arr[j+1].burst){
                proc temp =arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nId\tWt\tTt");
    int wait=0,tt=0,totWait=0,totTt=0;
    for(int i=0;i<n;i++){
        tt=tt+arr[i].burst;
        printf("\n%d\t%d\t%d",arr[i].id,wait,tt);
        totTt += tt;
        totWait += wait;
        wait = wait + arr[i].burst;
    }
    printf("\nAvg tt = %f \nAvg wt = %f\n",(float)totTt/n,(float)totWait/n);
}