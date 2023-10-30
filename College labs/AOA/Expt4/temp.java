import java.util.Scanner;

public class temp {
    public static void main(String[] args) {
        
        float[] wt= {1, 3, 5, 4, 1, 3, 2};
        float[] profit= {5, 10, 15, 7, 8, 9, 4};
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements : ");
        float n = sc.nextFloat();

        for(int i=0;i<n;i++){
            
        }


        System.out.print("Enter max weight : ");
        float maxWt = sc.nextFloat();
        System.out.println("Maximum profit :" +fracKnap(wt,profit,maxWt));
    }

    private static float fracKnap(float[] wt, float[] profit, float wtEmpty) {
        float[] x = new float[profit.length];

        for(int i=0; i<profit.length; i++) x[i] =profit[i]/wt[i];

        for(int i =0;i <profit.length-1;i++){
            for(int j=0; j<profit.length-i-1 ; j++){
                if(x[j]<x[j+1]){
                    swap(x,j,j+1);
                    swap(profit,j,j+1);
                    swap(wt,j,j+1);
                }
            }
        }
        
        int i=0;
        float totalProfit=0, totalWt=0;
        while(i<profit.length && totalWt < wtEmpty){
            if(wt[i]<=wtEmpty) {
                totalProfit += profit[i];
                wtEmpty = wtEmpty - wt[i];
            }
            else{
                totalProfit = totalProfit + (wt[i]-wtEmpty)*profit[i]/wt[i];
            }
            i++;
        }

        for(int k=0; k<profit.length; k++) System.out.println(x[k] + " ");;
        return totalProfit;
    }

    private static void swap(float[] x, int a, int b) {
        float temp = x[a];
        x[a] = x[b];
        x[b] = temp;
    }
}