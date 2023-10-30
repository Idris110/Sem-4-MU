import java.util.Scanner;

public class InsertionSort{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of elements : ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.print("Enter the Elements : ");
        for(int i=0;i<n;i++) arr[i]= sc.nextInt();

        int swaps = IntsertnSort(arr);

        System.out.println("\nSorted array :");
        for (int k=0;k<n;k++) {
            System.out.print("\t"+arr[k]);
        }
        System.out.println("\n\nNumber of swaps : "+ swaps);
        sc.close();
    }
    
    private static int IntsertnSort(int[] arr) {
        int swaps=0;
        System.out.println("\n***Insertion Sort*** \nPasses :");
        for(int i=1;i<arr.length;i++){
            print(arr,i);
            int temp = arr[i];
            int j;
            for(j=i-1;j>=0;j--){
                if(arr[j]>temp){
                    arr[j+1] = arr[j];
                    swaps++;
                }
                else break;
            }
            arr[j+1]=temp;
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