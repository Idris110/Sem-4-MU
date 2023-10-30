Data segment

	msg db 0dh,0ah,"Minimum element of array is: $"
	arr db 20h, 50h, 30h, 10h, 40h

Data ends

Code segment
	assume CS:Code,DS:Data

start:
    mov ax, Data
    mov DS, ax

    mov dx,offset msg ;----- Display contents of variable msg
	mov ah,09h
	int 21h

    mov cx, 05h
    lea SI, arr

    ; mov bl,[SI]
    ; inc SI

    iterate :
        mov bl, [SI]
        inc SI
        cmp bl, [SI]
        jc skip
        skip :
        loop iterate
    
    mov al,bl
    and al,0F0h
    ror al,4h
    call HexToAscii
    mov al,bl
    and al,0Fh
    call HexToAscii
    
	mov ah,4ch ; Terminate the program
	int 21h

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