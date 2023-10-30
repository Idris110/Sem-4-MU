#include<bits/stdc++.h>
using namespace std;

struct file
{
    string fileName;
    int start,end;
};

int checkOverwrite(int st,int end,vector <file> file){
    for(int i=0;i<file.size();i++){
        if(st>=file[i].start && st<=file[i].end || end>=file[i].start && end<=file[i].end)
        return 1;
    }
    return 0;
}

int main(){
    vector <file> file;
    int ch;

    while(1){
        printf("\nContiguous file allocation\n");
        printf("1.File Creation\n");
        printf("2.File Deletion\n");
        printf("3.Display File Allocation Table\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
                string fName;
                int st,end;
        switch(ch){
            case 1: 
                printf("Enter the name of the file, Start & end\n");
                cin>>fName>>st>>end;
                if(checkOverwrite(st,end,file)) cout<<"File cannot be saved\n";
                else{
                    file.push_back({fName,st,end});
                }
                
                break;
            case 2:
                printf("Enter the name of the file to be deleted\n");
                cin>>fName;
                for(int i=0;i<file.size();i++){
                    if(fName==file[i].fileName)
                    file.erase(file.begin()+i);
                }
                break;
            case 3:
                printf("File Allocation Table\n");
                printf("File Name Start Block-Length\n");
                
                for(int i=0;i<file.size();i++) 
                cout<<file[i].fileName<<file[i].start<<file[i].end<<endl;
                
                break;
            case 4:
                exit(1);
            default:
                printf("invalid");
        }
        getchar();
    }

}
