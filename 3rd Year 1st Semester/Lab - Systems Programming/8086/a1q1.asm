.model small
.stack 100h

.data

msg db "Avraneel Pal a1q1.asm$"

.code 

    mov ax, @data
    mov ds, ax

    lea dx, msg

    mov ah, 09h
    int 21h

    mov ah, 4ch
    int 21h

end