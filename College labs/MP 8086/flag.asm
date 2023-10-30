Data segment

	msg db 0dh,0ah,"-- -- -- -- OF DF IF TF SF ZF -- AF -- PF -- CF$"
	newl db 0dh,0ah,"$"

Data ends

Code segment
	assume CS:Code,DS:Data

start:
    mov ax, Data
    mov DS, ax

    mov dx,offset msg  
	mov ah,09h
	int 21h
    mov dx,offset newl  
	mov ah,09h
	int 21h

    cld      ; clear dirn flag
    stc      ; set carry flag
    sti      ; set interrupt enable flag

    pushf
    pop bx

    mov cx,10h
    
    loop1 :
        mov ax, 8000h
        and ax,bx
        jz zero
        mov dl,31h
        mov ah,02h
	    int 21h
        jmp space
    
    zero :
        mov dl,30h
        mov ah,02h
	    int 21h

    space :
        mov dl,' '
        mov ah,02h
        int 21h
        int 21h

    sal bx,01h
    loop loop1
	
	mov ah,4ch
	int 21h

Code ends
end start
