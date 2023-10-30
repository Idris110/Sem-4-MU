.model small

.data
num1 db 03h     
num2 db 04h

.code
start:  mov AX, @data
        mov DS, AX
        mov AL, num1

        mul num2

        mov AH, 4ch
        int 21h
        end start
        end
