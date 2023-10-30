Data segment
    msg  db 10,13,"  Sorted array in descending order : $"
    msg1  db 10,13,"  $"
    arr   db 25h, 10h, 45h, 30h, 50h, 75h
Data ends

Code segment
           assume DS:Data,CS:Code
    start: 
           mov    ax,Data
           mov    ds,ax

       lea    SI,arr
       mov    cx,5
       mov    bx,0000h

    outerFor:
           lea    SI,arr
           mov    bl,[SI]
           inc    SI
           mov    bh,5

    innerLoop:
           dec    bh
           cmp    bl,[SI]
           jnc    skipSwap
           mov    dl,bl
           mov    bl,[SI]
           dec    SI
           mov    [SI],bl
           inc    SI
           mov    [SI],dl

    skipSwap:
           mov    bl,[SI]
           inc    SI
           cmp    bh,00h
           jnz    innerLoop
           loop   outerFor
       lea    SI,arr
       mov    cx,6
       lea    dx,msg
       mov    ah,09h
       int    21h

    output:     
           lea    dx,msg1
           mov    ah,09h
           int    21h
           mov    bl,00h
           mov    bl,[SI]
           and    bl,0f0h
           ror    bl,04h
           call   hexToAscii
           mov    bl,[SI]
           and    bl,0fh
           call   hexToAscii
           inc    SI
           loop   output
       mov    ah,4ch
       int    21h


hexToAscii proc
           cmp    bl,0ah
           jc     skip2
           add    bl,07h
    skip2: add    bl,30h
           mov    dl,bl
           mov    ah,02h
           int    21h
   
           ret
           endp
Code ends
end start
