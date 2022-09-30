.model small
.stack 100h

.data

.code

loading_data:
    mov ax, @data
    mov ds, ax
    mov ax, 00h

input: 
    mov ah, 01h ; data is stored in al
    int 21h

moving_data:
    mov dl, al

output:
    mov ah, 02h ; prints data in dl
    int 21h

mov ah, 4ch
int 21h

end