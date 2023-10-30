.model small

.data
num1 db 08h     
num2 db 01h
diff db 00h

.code
start:  mov AX, @data
        mov DS, AX
        mov AL, num1
        sub AL, num2
        mov diff, AL
        mov AH, 4ch
        int 21h
        end start
        end
