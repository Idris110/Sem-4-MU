import java.util.Scanner;

public class fractionalKnapsack {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of elements : ");
        int n = sc.nextInt();
        System.out.print("Enter capacity of knapsack : ");
        float max = sc.nextFloat();
        float[] w = new float[n];
        float[] p = new float[n];
        

        System.out.print("Enter weight & profit : ");
        for(int i=0;i<n;i++){
            w[i]= sc.nextFloat();
            p[i]= sc.nextFloat();
        }


        for(int i=0;i<n;i++)
            for(int j=0;j<n-i-1;j++){
                if((p[j]/w[j])<(p[j+1]/w[j+1])){
                    swap(w,j,j+1);
                    swap(p,j,j+1);
                }
            }
        int i=0;
        float weight=0,profit=0;
        while(i<n && weight<max){
            float x=1;
            if(weight+w[i] > max) x=(max-weight)/w[i];

            System.out.println("profit :"+p[i]+"\tfraction :"+x+"\tweight :"+w[i]);
            weight=weight+w[i]*x;
            profit=profit+p[i]*x;
            i++;
        }
        System.out.println("Total profit :" +profit);
    }

    private static void swap(float[] arr, int j, int i) {
        float temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}