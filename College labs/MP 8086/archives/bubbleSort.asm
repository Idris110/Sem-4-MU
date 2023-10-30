.model small
.data
    string1 db 52h,23h,0ffh,32h,10h
    string2 db ?
    temp    dw ?
.code
    start: 
           mov ax, @data
           mov ds, ax
           mov cl, 04h
           mov dl,03h
           lea si ,string1
           mov bx,si
           mov dh,[si]
    label1:
           inc si
           cmp dh, [si]
           jnc label2
           dec cl
           jnz label1
           jmp label3
    label2:
           dec cl
           mov ax,[si+1]
           mov temp,ax
           mov ax,[si]
           mov [si+1],ax
           mov ax,temp
           mov [si],ax
           jnz label1
    label3:
           mov si,bx
           mov cl,dl
           dec cl
           dec dl
           jnz label1
           mov ah, 4ch
           int 21h
end start