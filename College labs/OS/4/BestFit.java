import java.util.Scanner;

public class BestFit{
	static void bestFit(int blockSize[], int m, int processSize[], int n){
        int allocation[] = new int[n]; // Stores block id of the block allocated to a process
	
		for (int i = 0; i < allocation.length; i++) // Initially no block is assigned to any process
        allocation[i] = -1;
        
        System.out.println("\nProcess no.\tProcess Size\tBlock no.\tBlock size remaining");
		for (int i=0; i<n; i++){   
			int bestIdx = -1;  // Find the best fit block for current process
            boolean allocated = false;
			for (int j=0; j<m; j++){
				if (blockSize[j] >= processSize[i]){
					if (allocated == false){ //to assign block first time
                        bestIdx = j;
                        allocated=true;
                    }
					else if (blockSize[bestIdx] > blockSize[j])
						bestIdx = j;
				}
			}
			if (allocated == true){		 //if allocated update allocation list and reduce corresp block size
				allocation[i] = bestIdx; // allocate block j to p[i] process
				blockSize[bestIdx] -= processSize[i]; // Reduce available memory in this block.
			}

            System.out.print(" " + (i+1) + "\t\t" + processSize[i] + "\t\t" );//printing output
			if (allocation[i] != -1)
				System.out.print(allocation[i] + 1 + "\t\t" + blockSize[allocation[i]]);
			else
				System.out.print("Not Allocated");
			System.out.println();
		}
	}
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of processes : ");
		int n = sc.nextInt();
		int processSize[] = new int[n];
        System.out.println("Enter the processes : ");
        for(int i=0;i<n;i++){
            System.out.print("Process No:"+ (i+1) + " =");
            processSize[i]=sc.nextInt();
        }
        System.out.print("\nEnter the number of memory blocks : ");
		int m = sc.nextInt();
        int blockSize[] = new int[m];
        System.out.println("Enter the memory blocks : ");
        for(int i=0;i<m;i++){
            System.out.print("Block No:"+ (i+1) + " =");
            blockSize[i]=sc.nextInt();
        }
		bestFit(blockSize, m, processSize, n);
		sc.close();
	}
}
