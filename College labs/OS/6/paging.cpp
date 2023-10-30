#include <bits/stdc++.h>
using namespace std;

int bin2dec(char *s, int n){
   int res = 0;
   for(int i = n-1; i >= 0; i--)
       res += (s[i]-'0')*(1<<i);
   return res;
}

int checkTable(int page, int pt[][3]){
   return pt[page][2];
}

int main(){
   int processSize, pageSize, physicalMem;
   cout << "Enter process size in KB:\n";
   cin >> processSize;
   cout << "Enter page size in bytes:\n";
   cin >> pageSize;
   cout << "Enter size of physical memory in MB:\n";
   cin >> physicalMem;

   int frames = (physicalMem*(1<<20))/pageSize;
   printf("\nNo. of frames in memory: %d (i.e. 2^%.0f)\n", frames, log2(frames));

   int n = (processSize*(1<<10))/pageSize;
   printf("No. of entries in page table: %d (i.e. 2^%.0f)\n", n, log2(n));

   float phy_add_bits = log2(physicalMem*(1<<20));
   printf("No. of bits in physical address: %0.f\n", phy_add_bits);

   float log_add_bits = log2(processSize*(1<<10));
   printf("No. of bits in logical address: %0.f\n", log_add_bits);
   printf("\nPage Segment: %0.f bits\tOffset: %0.f bits\n", log2(n), log_add_bits-log2(n));

   int pt[n][3]; 
   cout << "\nInput page table: (Page No | Frame No | Valid Bit)\n";
   for(int i = 0; i < 4; i++) {
       scanf("%d %d %d", &pt[i][0], &pt[i][1], &pt[i][2]);
   }
  
   int repeat=1;
   while(repeat){
      char logAdd[(int)log_add_bits];
      printf("Input logical address: ");
      scanf("%s", logAdd);
      int page = bin2dec(logAdd, (int)log2(n));
      printf("%s", (checkTable(page, pt) ? "Page Hit\n":"Page Fault\n"));
      cout<<"\nTo continue enter 1 else 0 : ";
      cin>>repeat;
   }
   return 0;
   
}