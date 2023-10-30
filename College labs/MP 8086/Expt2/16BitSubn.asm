Data segment

	msg db 0dh,0ah,"Enter first number: $"
	msg1 db 0dh,0ah,"Enter second number: $"
	result db 0dh,0ah,"The Result of subtraction is: $"

Data ends

Code segment
	assume CS:Code,DS:Data

start:
    mov ax, Data
    mov DS, ax

    mov dx,offset msg ;----- Display contents of variable msg
	mov ah,09h
	int 21h

	mov ah,01h ; To accept 4bits 10s input of higher nibble
	int 21h
    call AsciiToHex
    mov bl, al
    rol bl,4

	mov ah,01h ; To accept 4bits units input of higher nibble
	int 21h
    call AsciiToHex
    add bl,al
    mov ch,bl

	mov ah,01h ; To accept 4bits 10s input of lower nibble
	int 21h
    call AsciiToHex
    mov bl, al
    rol bl,4

	mov ah,01h ; To accept 4bits units input of lower nibble
	int 21h
    call AsciiToHex
    add bl,al
	mov cl,bl

    mov dx,offset msg1 ;----- Display contents of variable msg1
	mov ah,09h
	int 21h

	mov ah,01h ; To accept 4bits 10s input
	int 21h
    call AsciiToHex
    mov bl, al
    rol bl,4

	mov ah,01h ; To accept 4bits units input
	int 21h
    call AsciiToHex
    add bl,al
	mov bh,bl

	mov ah,01h ; To accept 4bits 10s input of lower nibble
	int 21h
    call AsciiToHex
    mov bl, al
    rol bl,4

	mov ah,01h ; To accept 4bits units input of lower nibble
	int 21h
    call AsciiToHex
    add bl,al	

    sub bx,cx;-------------------main subn

    mov dx,offset result ; Display contents of string result
	mov ah,09h
	int 21h

	mov cl,bh
    and bh,0f0h
    rol bh,4h; interchange nibbles

    mov  al,bh
    call HexToAscii


    mov al,cl
    and al,0fh
    call HexToAscii


    mov cl,bl
    and bl,0f0h
    rol bl,4h; interchange nibbles

    mov  al,bl
    call HexToAscii

    mov al,cl
    and al,0fh
    call HexToAscii


	mov ah,4ch ; Terminate the program
	int 21h

    	AsciiToHex proc
		cmp al,41h ; If it is greater than or equal to 41 then we also need to sub 8h along with 30
		jc skip
		sub al, 07h
		skip: sub al, 30h
		ret
		endp

        HexToAscii proc 
		cmp al,0ah ; If it is greater than or equal to 0a then we also need to add 07 along with 30
		jc skip1
		add al,07h
		skip1: add al,30h
	    mov dl, al; display
		mov ah,02h
		int 21h	
		ret
		endp
Code ends
end start
