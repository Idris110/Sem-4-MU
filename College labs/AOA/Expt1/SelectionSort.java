import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of elements : ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.print("Enter the Elements : ");
        for(int i=0;i<n;i++) arr[i]= sc.nextInt();

        int swaps = selectnSort(arr);

        System.out.println("\nSorted array :");
        for (int k=0;k<arr.length;k++) {
            System.out.print("\t"+arr[k]);
        }
        System.out.println("\n\nNumber of swaps : "+ swaps);
    }

    private static int selectnSort(int[] arr) {
        int swaps=0;
        System.out.println("\n***Selection Sort*** \nPasses :");

        for(int i=0;i<arr.length;i++){
            print(arr,i);
            int min = i;
            for(int j=i+1;j<arr.length;j++){
                if(arr[min]>arr[j]) min = j;
            }
            int temp = arr[i];
            arr[i] = arr [min];
            arr[min] = temp;
            swaps++;
        }
        return swaps;
    }

    private static void print(int[] arr, int i) {
        for (int k=0;k<arr.length;k++) {
            System.out.print("\t"+arr[k]);
            if(i-1 == k) System.out.print("   |");
        }
        System.out.println();
    }
}
