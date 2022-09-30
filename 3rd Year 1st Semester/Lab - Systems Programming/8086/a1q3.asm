.model small
.stack 100h

.data

.code

loading_data:
    mov ax, @data
    mov ds, ax
    mov ax, 00h

;your code goes here

mov ah, 4ch
int 21h

end