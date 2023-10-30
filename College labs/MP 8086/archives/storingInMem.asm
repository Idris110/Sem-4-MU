.model small

.data
num1 dw 1234h     
num2 dw 5678h     

.code
start:  mov AX, @data
        mov DS, AX
        mov bx, [0010h]

        ; mov AX, num1

        ; mov dl, al
        ; and dl, 0fh
        ; mov ds:[bx] ,dl
        ; inc bx

        ; mov dl, al
        ; and dl, 0f0h
        ; rol dl, 4
        ; mov ds:[bx] ,dl
        ; inc bx
        
        ; mov dl, ah
        ; and dl, 0fh
        ; mov ds:[bx] ,dl
        ; inc bx

        ; mov dl, ah
        ; and dl, 0f0h
        ; rol dl, 4
        ; mov ds:[bx] ,dl
        ; inc bx

        mov dl, 04h
        mov cl, 00h

        loop1 : mov ds:[bx], cl
                inc cl
                inc bx
                dec dl
                jnz loop1

        
        mov AH, 4ch
        int 21h
        end start
        end