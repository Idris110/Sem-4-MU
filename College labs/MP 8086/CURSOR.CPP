#include<iostream.h>
#include<stdlib.h>

int main(){
int size = 0;
 while(size != 4){
	cout<<"-----CURSOR-----"<<endl;
	cout<<"1. Increment\n2. Decrement\n3. Disable\n4. Exit"<<endl;
	cout<<"Enter choice: ";
	int choice;
	cin>>choice;

	switch(choice){
	case 1:{
		size ++;
		asm{
		    mov cx, size;
		    mov ah, 01h;
		    int 10h;
		}
		break;
	}
	case 2:{
		size --;
		asm{
		    mov cx, size;
		    mov ah, 01h;
		    int 10h;
		}
		break;
	}
	case 3:{
		asm{
		    mov cl, 20h
		    mov ah, 01h;
		    int 10h;
		}
		break;
	}
	case 4: return 0;

	}
 }
 return 0;
}
