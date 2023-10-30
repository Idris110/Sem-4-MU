// #include<iostream.h>
// #include<conio.h>

// int main()

// {
// clrscr();
// int a,b,res;
// cout << "Enter first number" << endl;
// cin>>a;
// cout << "Enter second number" << endl;
// cin >> b;
// cout<<endl;

// asm mov ax,a;

// asm mov bx,b;
// bck:

// asm cmp ax,bx;
// asm jc second; 
// first:

// asm sub ax,bx;
// asm jmp chk;
// second:
// asm sub bx,ax;
// chk: asm cmp ax,bx;
// asm jnz bck;
// asm mov res,ax;
// cout<<"The GCD is: "<<res;
// getch();
// }