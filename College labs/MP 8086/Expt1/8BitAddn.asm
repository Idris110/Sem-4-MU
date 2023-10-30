Data segment

	msg db 0dh,0ah,"Enter first number: $"
	msg1 db 0dh,0ah,"Enter second number: $"
	result db 0dh,0ah,"The Result of Subtration is: $"

Data ends

Code segment
	assume CS:Code,DS:Data

start:
    mov ax, Data
    mov DS, ax

    mov dx,offset msg  
	mov ah,09h
	int 21h
	mov ah,01h  
	int 21h

    call AsciiConv2
    mov bl, al
    mov dx,offset msg1  
	mov ah,09h
	int 21h

	mov ah,01h  
	int 21h
    call AsciiConv2

    add bl,al
    mov cl,bl
    mov dx,offset result
	mov ah,09h
	int 21h

    and bl,0f0h
    rol bl,4h
    mov  al,bl
    call AsciiConv1
    mov dl, al
	mov ah,02h
	int 21h

    mov al,cl
    and al,0fh
    call AsciiConv1
    mov dl, al
	mov ah,02h
	int 21h
	
	mov ah,4ch
	int 21h

    	AsciiConv2 proc
		cmp al,41h 
		jc skip
		sub al, 07h
		skip: sub al, 30h
		ret
		endp

        AsciiConv1 proc 
		cmp al,0ah
		jc skip1
		add al,07h
		skip1: add al,30h
		ret
		endp
Code ends
end start
