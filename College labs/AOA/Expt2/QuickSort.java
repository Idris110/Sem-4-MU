import java.util.Scanner;

public class QuickSort {
    static int swaps = 0;
    public static void main(String[] args) {
        // int[] arr = {5,4,7,6,2,1,3};
        // quickSort(arr, 0, arr.length-1);
        // for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");

        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of elements : ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.print("Enter the Elements : ");
        for(int i=0;i<n;i++) arr[i]= sc.nextInt();
        System.out.println("Passes :");
        quickSort(arr, 0, arr.length-1);
        System.out.println("\nSorted array :");
        for (int k=0;k<n;k++) {
            System.out.print("\t"+arr[k]);
        }
        System.out.println("\n\nNumber of swaps : "+ swaps);
        sc.close();

    }

    private static void quickSort(int[] arr, int lb, int ub) {
        if(lb<ub){
            for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
            System.out.println();
            int piv = partition(arr, lb, ub);
            quickSort(arr, lb, piv-1);
            quickSort(arr, piv+1, ub);
        }
    }

    private static int partition(int[] arr, int lb, int ub) {
        int start=lb, end=ub, pivot=arr[lb];

        while(start<end){
            while(start<ub && arr[start]<=pivot) start++;
            while(arr[end]>pivot) end--;

            if(start<end) swap(arr,start,end);
        }
        swap(arr, lb, end);
        return end;
    }

    private static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        swaps++;
    } 
}
