#include <stdio.h>

typedef struct process{
    int process_id;
    int priority;
    int burst_time;
} process;

void swap(process *a, process *b){
    process t = *a;
    *a = *b;
    *b = t;
}

void sort_by_priority(process *arr, int n){
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].priority>arr[j+1].priority){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process arr[n];
    for(int i = 0; i < n; i++){
        arr[i].process_id = i+1;
        printf("\nProcess_id %d\n", i+1);
        printf("Enter priority: ");
        scanf("%d", &arr[i].priority);
        printf("Enter burst time: ");
        scanf("%d", &arr[i].burst_time);
    }
    sort_by_priority(arr, n);
    
    int wait = 0, turn = 0, tot_wait = 0;
    printf("The process are :\n");
    printf("ID\tFrom\tTo\tWT\tTAT\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\n",arr[i].process_id,wait,wait+arr[i].burst_time,wait, wait+arr[i].burst_time);
        if(i != n-1) {
            tot_wait += wait+arr[i].burst_time;
        }
        turn += wait+arr[i].burst_time;
        wait += arr[i].burst_time;
    }
    printf("Average Waiting Time: %f time units\n", (float)tot_wait/n);
    printf("Average Turnaround Time: %f time units\n", (float)turn/n);
    return 0;
}