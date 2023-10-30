.model small
.data
string1 db 52h,23h,0ffh,32h,10h
.code
start:
mov ax, @data
mov ds, ax
mov cl, 04h
lea si ,string1
mov al,[si]
label1:
inc si
cmp al, [si]
jnc label2
mov al,[si]
label2:
 dec cl
jnz label1
mov ah, 4ch
int 21h
end start