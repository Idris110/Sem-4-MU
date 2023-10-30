#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int start[10],num=0,count=0,length[10],j,f=1,i=0;
    char name[20][10];
    char del[2];
    int ch=0;
    while(1){
        printf("Contiguous file allocation\n");
        printf("1.File Creation\n");
        printf("2.File Deletion\n");
        printf("3.Display File Allocation Table\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("Enter the name of the file\n");
                scanf("%s",&name[i][0]);
                printf("Enter the start block of the file\n");
                scanf("%d",&start[i]);
                printf("Enter the length of the file\n");
                scanf("%d",&length[i]);
                num++;
                i++;
                if(f==1){
                    f++;
                }
                for(j=0;j<num;j++){
                    if(start[j+1]<=start[j] || start[j+1]>=length[j]){
                        
                    }
                    else{
                        count++;
                    }
                }
                if(count==1){
                    printf("%s cannot be allocated disk space\n",name[i-1]);
                }
                else{
                    printf("file %s allocated disk space\n",name[i-1]);
                }
                break;
            case 2:
                printf("Enter the name of the file to be deleted\n");
                scanf("%s",&del[0]);
                printf("file %s deleted\n",&del[0]);
                f--;
                f--;
                break;
            case 3:
                printf("File Allocation Table\n");
                printf("File Name Start Block Length\n");
                if(f==2){
                    printf("%s %d %d\n",name[0],start[0],length[0]);
                }
                for(int k=0,n=1;k<num && n<num ;k++,n++){
                    if(start[k+1]<=start[k] || start[k+1]>=length[k]){
                        printf("%s %d %d\n",name[n],start[n],length[n]);
                    }
                }
                break;
            case 4:
                exit(1);
            default:
                printf("invalid");
        }
        getchar();
    }
    return 0;
}