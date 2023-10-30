import java.util.Scanner;

public class MergeSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of elements : ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.print("Enter the Elements : ");
        for(int i=0;i<n;i++) arr[i]= sc.nextInt();
        System.out.println("Passes :");
        mergeSort(arr, 0, arr.length-1);
        System.out.println("\nSorted array :");
        for (int k=0;k<n;k++) {
            System.out.print("\t"+arr[k]);
        }
        sc.close();
    }

    private static void mergeSort(int[] arr, int lb, int ub) {
        if (lb < ub) {
            for (int l = lb; l <= ub; l++)
                System.out.print(arr[l] + " ");
            System.out.println();

            int mid = (lb + ub) / 2;
            mergeSort(arr, lb, mid);
            mergeSort(arr, mid + 1, ub);
            merge(arr, lb, mid, ub);

        }
    }

    private static void merge(int arr[], int lb, int mid, int ub) {
        int i = lb, j = mid + 1, k = 0;
        int[] tempArr = new int[ub-lb+1];
        while (i <= mid && j <= ub) {
            if (arr[i] < arr[j]) {
                tempArr[k] = arr[i];
                i++;
            } else {
                tempArr[k] = arr[j];
                j++;
            }
            // if(k>=(ub-lb+1)) System.out.println(k+":k ub:"+ub+" lb:"+lb);
            k++;
        }
        if (i > mid) {
            while (j <= ub) {
                tempArr[k] = arr[j];
                j++;
                k++;
            }
        } else {
            while (i <= mid) {
                tempArr[k] = arr[i];
                i++;
                k++;
            }
        }

        for (k = lb; k <= ub; k++) { //copy tempArr to main arr
            arr[k] = tempArr[k-lb];
        }
    }
}