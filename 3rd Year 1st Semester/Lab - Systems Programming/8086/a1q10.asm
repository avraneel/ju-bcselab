.model small
.stack 100h

.data

letters db "ABCDEFGHIJKLMNOPQRSTUVWXYZ$"

.code

loading_data:
    mov ax, @data
    mov ds, ax
    ; mov ax, 00h

printing:
    lea dx, letters

    mov ah, 09h
    int 21h

mov ah, 4ch
int 21h

end