.model small

.data
num1 db 01h     
num2 db 01h
sum db 00h

.code
start:  mov AX, @data
        mov DS, AX
        mov AL, num1
        add AL, num2
        mov sum, AL
        mov AH, 4ch
        int 21h
        end start
        end
