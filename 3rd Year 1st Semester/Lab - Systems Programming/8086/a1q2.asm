.model small
.stack 100h

.data
    newline db 10, 13, '$'

.code 

loading_data:
    mov ax, @data
    mov ds, ax

reseting_ax:
    mov ax, 00h

input:
    mov ah, 01h ; input character will be stored in AL
    int 21h

print_newline:
    lea dx, newline

    mov ah, 09h
    int 21h

convert:
    mov dx, 00h ; dx had newline variable, so resetting it
    add al, 20h
    mov dl, al 
    ; For the next instruction where we give the interupt to print a character,
    ; the character in DL register would be printed

output:
    mov ah, 02h ; prints character in dl
    int 21h

mov ah, 4ch
int 21h

end
