.model small
.stack 100h

.data

prompt1 db "Maximum: $"
prompt2 db "Minimum: $"

arr db 01h, 02h, 03h, 04h

.code

loading_data:
    mov ax, @data
    mov ds, ax
    xor ax, ax



