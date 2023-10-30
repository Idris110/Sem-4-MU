
Data segment

	msg db 0dh,0ah,"Enter first number: $"
	msg1 db 0dh,0ah,"Enter second number: $"
	result db 0dh,0ah,"The Result is: $"

Data ends

Code segment
	assume CS:Code,DS:Data

start:
	mov ax,Data ; Move Data to Data Segment
	mov DS,ax

	mov dx, offset msg
	mov ah, 09h
	int 21h
	
	mov ah, 01h
	int 21h

	sub al, 30h
	mov bl, al
	rol bl, 4

	mov ah, 01h
	int 21h

	sub al, 30h

	add al, bl
	mov cl, al


	mov dx, offset msg1
	mov ah, 09h
	int 21h
	
	mov ah, 01h
	int 21h

	sub al, 30h
	mov bl, al
	rol bl, 4

	mov ah, 01h
	int 21h

	sub al, 30h

	add al, bl

	add cl, al  ;Main addion

	mov bl, cl

	and bl, 0f0h
	rol bl, 4

	call AsciiConvsssssssss




	mov ah,4ch ; Terminate the program
	int 21h

Code ends
end start