
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
	mov ch, al
	
    mov ah, 01h  ; now next 2 digits (16 bits)
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
    mov dh, al
	
    mov ah, 01h ;*******
	int 21h

	sub al, 30h
	mov bl, al
	rol bl, 4

	mov ah, 01h
	int 21h

	sub al, 30h

	add al, bl
    mov dl, al

    mov ax,dx
	mul cx  ; Main Multiplication

    mov cx, dx
	mov bx, ax

    mov dx,offset result
	mov ah,09h
	int 21h

	mov ax, bx
        mov bx, [0010h]

        mov dl, al
        and dl, 0fh
        mov ds:[bx] ,dl
        inc bx

        mov dl, al
        and dl, 0f0h
        rol dl, 4
        mov ds:[bx] ,dl
        inc bx
        
        mov dl, ah
        and dl, 0fh
        mov ds:[bx] ,dl
        inc bx

        mov dl, ah
        and dl, 0f0h
        rol dl, 4
        mov ds:[bx] ,dl
        inc bx
        
        mov ax, cx; ------next 16 bit
        mov dl, al
        and dl, 0fh
        mov ds:[bx] ,dl
        inc bx

        mov dl, al
        and dl, 0f0h
        rol dl, 4
        mov ds:[bx] ,dl
        inc bx
        
        mov dl, ah
        and dl, 0fh
        mov ds:[bx] ,dl
        inc bx

        mov dl, ah
        and dl, 0f0h
        rol dl, 4
        mov ds:[bx] ,dl

	; mov bx, [0018h]
	mov cl, 08h
	again :	mov ch, ds:[bx]
			call AsciiConv

			mov dl, ch
			mov ah, 02h
			int 21h
			dec bx
			dec cl
			jnz again


    ; and bh, 0f0h
    ; ror bh, 4
    ; call AsciiConv

    ; mov dl,bh
	; mov ah,02h
	; int 21h

    ; and ch, 0fh
    ; mov bh, ch
    ; call AsciiConv

    ; mov dl,bh
	; mov ah,02h
	; int 21h
    
    
    ; and bl, 0f0h
    ; ror bl, 4
    ; mov bh, bl
    ; call AsciiConv

    ; mov dl,bh
	; mov ah,02h
	; int 21h

    ; and cl, 0fh
    ; mov bh, cl
    ; call AsciiConv

    ; mov dl,bh
	; mov ah,02h
	; int 21h


	mov ah,4ch
	int 21h

	AsciiConv proc ; Compare to 0a if it is less than A then we need to add only 30
		cmp ch,0ah ; If it is greater than or equal to 0a then we also need to add 07
		jc skip
		add ch,07h
		skip: add ch,30h
		ret
		endp

Code ends
end start