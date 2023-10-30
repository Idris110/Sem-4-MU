
Data segment

	msg db 0dh,0ah,"Enter first number: $"
	msg1 db 0dh,0ah,"Enter second number: $"
	result db 0dh,0ah,"The Result is: $"

Data ends

Code segment
	assume CS:Code,DS:Data

start:
	mov ax,Data 
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

	mul cl  ;Main multiplication

    mov cx, ax
    mov bx, ax

    mov dx,offset result
	mov ah,09h
	int 21h

    and bh, 0f0h
    ror bh, 4
    call AsciiConv

    mov dl,bh
	mov ah,02h
	int 21h

    and ch, 0fh
    mov bh, ch
    call AsciiConv

    mov dl,bh
	mov ah,02h
	int 21h
    
    
    and bl, 0f0h
    ror bl, 4
    mov bh, bl
    call AsciiConv

    mov dl,bh
	mov ah,02h
	int 21h

    and cl, 0fh
    mov bh, cl
    call AsciiConv

    mov dl,bh
	mov ah,02h
	int 21h


	mov ah,4ch
	int 21h

	AsciiConv proc ; Compare to 0a if it is less than A then we need to add only 30
		cmp bh,0ah ; If it is greater than or equal to 0a then we also need to add 07
		jc skip
		add bh,07h
		skip: add bh,30h
		ret
		endp

Code ends
end start